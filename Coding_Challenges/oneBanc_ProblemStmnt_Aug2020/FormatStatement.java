import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Pattern;


public class FormatStatement{

    final static String FILE_1 = "HDFC-Input-Case1.csv";
    final static String FILE_2 = "ICICI-Input-Case2.csv";
    final static String FILE_3 = "Axis-Input-Case3.csv";
    final static String FILE_4 = "IDFC-Input-Case4.csv";

    final static String DOMESTIC = "Domestic";
    final static String INTERNATIONAL = "International";

    public static void main(String[] args) throws Exception{
        // System.out.println("Hello World");
        Scanner sc = new Scanner(new File(FILE_2));
        sc.useDelimiter("\n");

        String transactionType="";
        String name="";
        int amountFlag=0;
        int dateIndex=0, tDescriptionIndex=0, creditIndex=0, debitIndex=0, amountIndex=0;

        // TreeMap to store the record objects so that they are automatically sorted based on date when writing to file
        Map<Date, Record> recordsMap = new TreeMap<Date, Record>();


        while(sc.hasNext()){

            String line = sc.next();

            if(line.length() > 4){      // to eliminate unnecessary strings like ",,,"

                // System.out.println(line);

                if(Pattern.compile("[0-9]").matcher(line).find()){
                    // If a line contains a number, then it is a record
                    String[] info = line.split(",");

                    // create Record object
                    Record record = new Record();

                    record.transactionType = transactionType;
                    record.cardName = name;
                    record.date = info[dateIndex];
                    
                    if(transactionType.equals(DOMESTIC)){
                        record.transactionDescription = info[tDescriptionIndex];
                        record.currency = "INR";
                    }
                    else{
                        record.transactionDescription = info[tDescriptionIndex];
                        record.currency = record.transactionDescription.substring(record.transactionDescription.lastIndexOf(" ")+1);
                        record.transactionDescription = record.transactionDescription.replace(record.currency, "");
                    }

                    record.location = record.transactionDescription.trim().substring(record.transactionDescription.trim().lastIndexOf(" ")+1);


                    if(amountFlag==1){
                        String amount = info[amountIndex];

                        // if amount contains "cr" then it is credit and debit is zero
                        if(amount.contains("cr")){
                            record.credit = amount.split(" ")[0];
                            record.debit = "0";
                        }
                        else{
                            record.debit = amount;
                            record.credit = "0";
                        }      
                    }
                    else{
                        // fill credit and debit based on creditIndex and debitIndex (Handle if they are empty)
                        record.debit = info[debitIndex];
                        if(record.debit.isBlank())
                            record.debit = "0";

                        record.credit = info[creditIndex];
                        if(record.credit.isBlank())
                            record.credit = "0";
                    }

                    
                    // save the Record object in TreeMap

                    // date parsing 
                    DateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
                    Date d = dateFormat.parse(record.date);
                    recordsMap.put(d, record);
                }

                else{
                    // if a line doesn't contain a number, there are 3 possibilies -

                    // 1. It may be transaction type    (check the string for Domestic and International)
                    if(line.contains("Domestic Transaction"))
                        transactionType = DOMESTIC;
                    else if(line.contains("International Transaction"))
                        transactionType = INTERNATIONAL;

                    // 2. It may be a card name     (length of string is less than 15)
                    else if(line.length() <= 15){
                        line = line.replaceAll(",", "");
                        name = line.trim();
                    }

                    // 3. It may be the order of records (column headers)
                    else{
                        if(line.contains("Amount"))
                            amountFlag = 1;
                        else
                            amountFlag = 0;

                        String[] words = line.split(",");

                        if(amountFlag==1){
                            for(int i=0; i<3; i++){
                                if(words[i].contains("Date"))
                                    dateIndex = i;
                                else if(words[i].contains("Amount"))
                                    amountIndex = i;
                                else
                                    tDescriptionIndex = i;
                            }
                        }
                        else{
                            for(int i=0; i<4; i++){
                                if(words[i].contains("Date"))
                                    dateIndex = i;
                                else if(words[i].contains("Debit"))
                                    debitIndex = i;
                                else if(words[i].contains("Credit"))
                                    creditIndex = i;
                                else
                                    tDescriptionIndex = i;
                            }
                        }
                    }
                    
                }

            }

        }

        // print all Record objects and see if they are in order based on Dates
        for(Map.Entry<Date, Record> entry: recordsMap.entrySet()){
            Record record = new Record();
            record = entry.getValue();

            System.out.println("Date: " + record.date);
            System.out.println("Transaction Description: "+ record.transactionDescription);
            System.out.println("Debit: " + record.debit);
            System.out.println("Credit: "+ record.credit);
            System.out.println("Currency: "+ record.currency);
            System.out.println("CardName: " + record.cardName);
            System.out.println("Transaction: " + record.transactionType);
            System.out.println("Location: "+ record.location);
            System.out.println("\n------------------------------------------------------------------------------------------\n");

        }

        sc.close();
    }
}

class Record{
    String date;
    String transactionDescription;
    String debit;
    String credit;
    String currency;
    String cardName;
    String transactionType;
    String location;
}