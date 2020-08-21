import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class FormatStatement{

    final static String FILE_1 = "HDFC-Input-Case1.csv";
    final static String FILE_2 = "ICICI-Input-Case2.csv";
    final static String FILE_3 = "Axis-Input-Case3.csv";
    final static String FILE_4 = "IDFC-Input-Case4.csv";

    public static void main(String[] args) throws Exception{
        // System.out.println("Hello World");
        Scanner sc = new Scanner(new File(FILE_1));
        sc.useDelimiter("\n");

        String transactionType;
        String name;

        while(sc.hasNext()){

            String line = sc.next();

            if(line.length() > 4){      // to eliminate unnecessary strings like ",,,"

                System.out.println(line);

                if(Pattern.compile("[0-9]").matcher(line).find()){
                    // If a line contains a number, then it is a record

                }

                else{
                    // if a line doesn't contain a number, there are 3 possibilies

                    // 1. It may be transaction type    (check the string for Domestic and International)
                    if(line.contains("Domestic Transaction"))
                        transactionType = "Domestic";
                    else if(line.contains("International Transaction"))
                        transactionType = "International";

                    // 2. It may be a card name     (length of string is less than 15)
                    else if(line.length() <= 15){
                        Pattern p = Pattern.compile(",(.*?),");
                        Matcher m = p.matcher(line);
                        if(m.find())
                            name = m.group(1);
                    }

                    // 3. It may be the order of records (column headers)
                    else{

                    }
                    
                }

            }
            
        }

        sc.close();

        // date parsing 
        // String dateS = "19-01-2020";
        // DateFormat format = new SimpleDateFormat("dd-MM-yyyy");
        // Date d = format.parse(dateS);
        // System.out.println(d);
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