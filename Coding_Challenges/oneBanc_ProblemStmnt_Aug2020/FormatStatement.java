import java.io.*;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.regex.Pattern;


public class FormatStatement{

    final static String INPUT_FILE_1 = "HDFC-Input-Case1.csv";
    final static String INPUT_FILE_2 = "ICICI-Input-Case2.csv";
    final static String INPUT_FILE_3 = "Axis-Input-Case3.csv";
    final static String INPUT_FILE_4 = "IDFC-Input-Case4.csv";

    final static String DOMESTIC = "Domestic";
    final static String INTERNATIONAL = "International";

    public static void main(String[] args){

        System.out.println("-------------------------------------------------------");
        System.out.println("|             STANDARDIZE CARD STATEMENTS             |");
        System.out.println("-------------------------------------------------------\n");

        System.out.println("1. "+INPUT_FILE_1);
        System.out.println("2. "+INPUT_FILE_2);
        System.out.println("3. "+INPUT_FILE_3);
        System.out.println("4. "+INPUT_FILE_4);
        System.out.println("5. Enter file name manually");
        System.out.println("6. Exit\n");

        Scanner input = new Scanner(System.in);
        int choice;

        do{
            String input_fileName = "None";
            int okFlag = 1;
            System.out.print("choice: ");
            choice = input.nextInt();

            switch(choice){
                case 1:
                    input_fileName = INPUT_FILE_1;
                    break;

                case 2:
                    input_fileName = INPUT_FILE_2;
                    break;

                case 3:
                    input_fileName = INPUT_FILE_3;
                    break;

                case 4:
                    input_fileName = INPUT_FILE_4;
                    break;

                case 5:
                    System.out.print("\nEnter filename: ");
                    input.nextLine();   // to ignore enter
                    input_fileName = input.nextLine();
                    break;

                case 6:
                    okFlag = 0;
                    System.out.println("\nThank you!!\n");
                    break;

                default:
                    System.out.println("Wrong input!!\n");
                    okFlag = 0;

            }

            if(okFlag==1){
                File inputFile = new File(input_fileName);

                String OUTPUT_FILENAME = inputFile.getName().replace("Input", "Output");
                File outputFile = new File(OUTPUT_FILENAME);

                try{
                    StandardizeStatement(inputFile, outputFile);
                    System.out.println("Successful !\n\n");
                }
                catch(IOException e){
                    System.out.println("An Error occured!! Couldn't read or write file\n\n");
                }
            }

        }while(choice>0 && choice<6);

        input.close();

    }

    static void StandardizeStatement(File inputFile, File outputFile) throws IOException{
        Scanner sc = new Scanner(inputFile);
        sc.useDelimiter("\n");      // using newLine as delimiter so that program read data line by line

        String transactionType="";
        String name="";
        int amountFlag=0;
        int dateIndex=0, tDescriptionIndex=0, creditIndex=0, debitIndex=0, amountIndex=0;

        // TreeSet to store the record objects so that we can sort them based on date when writing to file using comparator
        TreeSet<Record> recordsSet = new TreeSet<Record>(new MyDateComp());


        while(sc.hasNext()){

            String line = sc.next();

            if(line.length() > 4){      // to eliminate unnecessary strings like ",,,"

                // If a line contains a number, then it is a record
                if(Pattern.compile("[0-9]").matcher(line).find()){
                    String[] info = line.split(",");

                    // create Record object
                    Record record = new Record();

                    record.transactionType = transactionType;
                    record.cardName = name.replaceAll("\n", "").replaceAll("\r", "");
                    record.date = info[dateIndex];
                    
                    if(transactionType.equals(DOMESTIC)){
                        record.transactionDescription = info[tDescriptionIndex].replaceAll("\n", "").replaceAll("\r", "");
                        record.currency = "INR";
                    }
                    else{
                        record.transactionDescription = info[tDescriptionIndex].replaceAll("\n", "").replaceAll("\r", "");
                        record.currency = record.transactionDescription.substring(record.transactionDescription.lastIndexOf(" ")+1);
                        record.transactionDescription = record.transactionDescription.substring(0, record.transactionDescription.lastIndexOf(record.currency));
                    }

                    record.location = record.transactionDescription.trim().substring(record.transactionDescription.trim().lastIndexOf(" ")+1);


                    if(amountFlag==1){
                        String amount = info[amountIndex];

                        // if amount contains "cr" then it is credit and debit is zero
                        if(amount.contains("cr")){
                            record.credit = amount.split(" ")[0].replaceAll("[^\\d.]", ""); // to remove any char other than digits
                            record.debit = "0";
                        }
                        else{
                            record.debit = amount.replaceAll("[^\\d.]", "");
                            record.credit = "0";
                        }      
                    }
                    else{
                        // fill credit and debit based on creditIndex and debitIndex (Handle if they are empty)
                        record.debit = info[debitIndex].replaceAll("[^\\d.]", "");
                        if(record.debit.isBlank())
                            record.debit = "0";

                        record.credit = info[creditIndex].replaceAll("[^\\d.]", "");
                        if(record.credit.isBlank())
                            record.credit = "0";
                    }

                    
                    // save the Record object in TreeSet
                    recordsSet.add(record);
                }

                // if a line doesn't contain a number, there are 3 possibilies -
                else{

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

        sc.close();


        // write the Records in the output file
        FileWriter fileWriter = new FileWriter(outputFile);

        // output file will contain records sorted based on the Date of transaction
        fileWriter.write("Date,Transaction Description,Debit,Credit,Currency,CardName,Transaction,Location\n");
        for(Record record: recordsSet){
            fileWriter.write(record.getRow());
        }
        fileWriter.close();
    }
}


// this class is defined in the same file because it is only needed for the public FormatStatement class
class Record{
    String date;
    String transactionDescription;
    String debit;
    String credit;
    String currency;
    String cardName;
    String transactionType;
    String location;

    // returns the whole row to be inserted in output file
    String getRow(){
        String row;
        row = date + "," + transactionDescription + "," + debit + "," + credit + "," + currency + "," + cardName + "," + transactionType + "," + location + "\n";
        return row;
    }

    // returns date to help in comparator to sort record objects
    Date getDate(){
         // date parsing 
         DateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
         try{
             Date d = dateFormat.parse(date);
             return d;
         }
         catch(ParseException e){
             // if date couldn't be parsed, don't store the record
             Date t = getDate();
             System.out.println("Date couldn't be parsed for " + cardName + ": " + transactionDescription);
             return t;
         }
    }

    String getTransactionDescription(){
        return transactionDescription;
    }
}


// comparator class to sort record objects in TreeSet
class MyDateComp implements Comparator<Record>{

    @Override
    public int compare(Record r1, Record r2) {
        int x = r1.getDate().compareTo(r2.getDate());

        // same date returns 0
        if(x==0){
            return r1.getTransactionDescription().compareTo(r2.getTransactionDescription());
        }
        
        return x;
    }

}