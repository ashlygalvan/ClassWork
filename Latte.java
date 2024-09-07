/**
 * Class Explanation
 * The Latte class represents the ingridients for a pumpkin spice
 * latte and how customized it will be and the cost for it
 * @author Ashly Galvan
 * @version 1.1
 * @see LatteOrder
 * @see StarbzDriver
 */

 /**Main fucntion of Latte class */
public class Latte{
    /**Private String storing the cup size of the latte */
    private String m_sizeLatte;
    /**Private Integer storing the amount of pumps of Pumpkin Sauce the latte will get */
    private int m_pumpsOfPumpkin;
    /**Private String storing the type of milk the latte will have */
    private String m_milkType;
    /**Private Integer storing the amount of espresso shots the latte will have */
    private int m_espressoNo;
    /**Private boolean determining if the latte will have whipped cream or not */
    private boolean m_whippedCream;

    /**Default constructor; sets the values to default values */
    public Latte(){
        m_sizeLatte = "Grande";
        m_pumpsOfPumpkin = 4;
        m_milkType = "2% milk";
        m_espressoNo = 2;
        m_whippedCream = true;
    }
    /**Overloaded Constructor; this is where the values are initialized 
     * @param a, a String
     * @param b, an integer
     * @param c, a String
     * @param d, an integer
     * @param e, a boolean
    */
    public Latte(String a, int b, String c, int d, boolean e){
        m_sizeLatte = a;
        m_pumpsOfPumpkin = b;
        m_milkType = c;
        m_espressoNo = d;
        m_whippedCream = e;
    }

    /**Copy constructor; here is where the values are accessed outside of the class as these member varibales are private
     * @param Latte, Latte class
     */
    public Latte (Latte c){
        m_sizeLatte = c.m_sizeLatte;
        m_pumpsOfPumpkin = c.m_pumpsOfPumpkin;
        m_milkType = c.m_milkType;
        m_espressoNo = c.m_espressoNo;
        m_whippedCream = c.m_whippedCream;
    }

    /**Get method; used to call for the value of a method 
     * @return m_sizeLatte; a String
    */
    public String getSizeLatte(){
        return m_sizeLatte;
    }

    /**Get method; used to call for the value of a method
     * @return m_pumpsOfPumpkin; an integer
    */
    public int getPumpsOfPumpkin(){
        return m_pumpsOfPumpkin;
    }

    /**Get method; used to call for the value of a method
     * @return m_milkType; a String
     */
    public String getMilkType(){
        return m_milkType;
    }

    /**Get method; used to call for the value of a method 
     * @return m_espressoNo; an integer
    */
    public int getEspressoShot(){
        return m_espressoNo;
    }

    /**Get method; used to call for the value of a method this one will return
     * either true or false
     * @return m_whippedCream; a boolean
     */
    public boolean getWhippedCream(){
        return m_whippedCream;
    }

    /**calcCost method calculates the additions of a latte; total will be determined by how much
     * of each ingridient is added
     * @return totalCost, a double
     */
    public double calcCost(){
        double totalCost = 0.0;
        /**equalsIgnoreCase is used to take in the value no matter if the word is uppercase or lowercase*/
        if (m_sizeLatte.equalsIgnoreCase("tall")){
            totalCost += 2.00;
        }else if (m_sizeLatte.equalsIgnoreCase("venti")){
            totalCost +=3.00;
        }else{
            totalCost += 2.50;
        }
        if (m_pumpsOfPumpkin > 0){
            int temp;
            temp = m_pumpsOfPumpkin;
            totalCost += (double)temp*0.25;
        }
        if (m_espressoNo > 0){
            int temp2;
            temp2 = m_espressoNo;
            totalCost += (double)temp2;
        }
        if (m_whippedCream == true){
            totalCost += 0.50;
        }
        if (m_milkType.equalsIgnoreCase("almond")||m_milkType.equalsIgnoreCase("oat")){
            totalCost += 0.75;
        }
        if (m_milkType.equalsIgnoreCase("whole")||m_milkType.equalsIgnoreCase("2%")){
            totalCost += 0.0;
        }
        return totalCost;
     }

     /**toString method; this provides the print statements for the latte order
      * @return s, a String
      */
     public String toString(){
        String s = "";
        s += "Size: " + m_sizeLatte;
        s += "\nPumpkin Sauce Pumps: " + m_pumpsOfPumpkin;
        s += "\nMilk Type: " + m_milkType;
        s += "\nEspresso Shots: " + m_espressoNo;
        s += "\nWhipped Cream: " + m_whippedCream;
        return s;
     }

     /**Equals method; this will check if the Latte object is an equal to another latte
      * @param Object o, an object
      * @return false, if the lattes are not the same order
      * @return true, if the lattes are the same order
      * @return  this.m_sizeLatte.equals(c.m_sizeLatte)&&
            this.m_pumpsOfPumpkin == c.m_pumpsOfPumpkin &&
            this.m_milkType.equals(c.m_milkType) &&
            this.m_espressoNo == c.m_espressoNo &&
            this.m_whippedCream == c.m_whippedCream, this all checks the contents of the latte if it true
      */
     public boolean equals(Object o){
        if (this == o){
            return true;
        }
        if (!(o instanceof Latte)){
            return false;
        }
        Latte c = (Latte)o;
            return this.m_sizeLatte.equals(c.m_sizeLatte)&&
            this.m_pumpsOfPumpkin == c.m_pumpsOfPumpkin &&
            this.m_milkType.equals(c.m_milkType) &&
            this.m_espressoNo == c.m_espressoNo &&
            this.m_whippedCream == c.m_whippedCream;
      }
 }
