/**Class Explanation
 * The LatteOrder class represnts the order that is being made in the next class. 
 * Everything here will total the entire cost of all lattes that are order
 * @author Ashly Galvan
 * @version 1.1
 * @see Latte
 * @see StarbzDriver
 */

 /**Main function of the LatteOrder class */
public class LatteOrder{
    /**Private Latte Array; to take the lattes into an array */
    private Latte[] m_order;
    /**Private Integer; determines the number of lattes being ordered */
    private int m_numLattes;

    /**Default Constructor; set a default in how many lattes are being ordered to set the array and the number of lattes */
    public LatteOrder(){
        m_order = new Latte[1];
        m_order[0] = new Latte();
        m_numLattes = 1;
    }
    /**Overloaded contstructor; this will set the number of lattes that will be into the array and how many of them will be added */
    public LatteOrder(int latte){
        m_order = new Latte[latte];
        m_numLattes = 0;

    }
    /**Add method; This will add the lattes into the array and define if the latte will be added or not
     * @return 1; got added
     * @return -1; not added
     */
    public int addLatte(Latte latte){
        if (m_numLattes < m_order.length) {
            m_order[m_numLattes] = latte;
            m_numLattes++;
            return 1;
        } else {
            return -1;
        }
    
    }
    /**calcTotal method; this will add up all of the lattes together to create a single final total
     * @return totalCost; total cost of all lattes added together
     */
    public double calcTotal(){
        double totalCost = 0.0;
        for (int i = 0; i < m_numLattes; i++){
            totalCost += m_order[i].calcCost();
        }
        return totalCost; 
        }

    /**toString method; this prints out the text and the individual lattes in the driver class
     * @return s; a String
     */
    public String toString(){
        double totalCost = calcTotal();

        String s = "";
        s += "Order:\n";
        s += "Total Cost: $" + totalCost + "\n";
        s += "---------------------------------\n";

        for (int i = 0; i < m_numLattes; i++){
            s += "Latte: " + (i+1) + "\n";
            s += "  Cost: $" + m_order[i].calcCost() + "\n";
            s += "  Size: " + m_order[i].getSizeLatte() + "\n";
            s += "  Pumpkin Sauce Pumps: " + m_order[i].getPumpsOfPumpkin() + "\n";
            s += "  Milk Type: " + m_order[i].getMilkType() + "\n";
            s += "  Espresso Shot: " +m_order[i].getEspressoShot() + "\n";
            s += "  Whipped Cream: " + m_order[i].getWhippedCream() + "\n";
            s += "---------------------------------\n";
        }
        return s;

    }
}