class Drawing {

    // 1st method creating the 2D array to become a Canvas:
    public static char [][] createCanvas(char[][] myArr) {
        //we assign the number of rows and column that were coded into the main program to int and rows
        int rows = myArr.length;
        int cols = myArr[0].length;
        
        //iterate through the entire 2D array and assign it a whitespace
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                myArr[i][j] = ' ';
            }
        }

        //in this section we assign the entire column in index 0 and last number of the index with "|"
        for (int i=0; i < rows; i++){
            for (int j=0; j < cols; j++){
                if (j == 0 || j == cols - 1){
                    myArr [i][j] = '|';
                }
        
        //to save sometime, I did it in a for loop and then if statement to assign "=" to the entire top row and bttom row
               else if (i == 0 || i == rows -1 ){
                    myArr [i][j] = '=';
                }
            }
        }
        
        //I overwrote the colums/rows that were in the corners and added a "+" instead!
        myArr[0][0] = '+';
        myArr[0][cols - 1] = '+';
        myArr[rows - 1][0] = '+';
        myArr[rows - 1][cols - 1] = '+';
        
        //our return function which will return our new 2D array we created
        return myArr;
        }


    //2nd method to add characters into our array:
    // here I called to have an intake of 4 things when it is being called
    //the array, the character someone wants to add into an element of the array, and the x and y axis of the arrray
    public static char[][] addCharacter(char[][] myArr, char character, int x, int y){
        myArr[y][x] = character;
        return myArr;
    }


    //3rd method the method that will print out the entire array when the characters are added:
    public static void printCanvas(char[][] myArr){
    //we assign the rows and columns again in order to call for createCanvas method
    int rows = myArr.length;
    int cols = myArr[0].length;

        //This will print out numbers for the x axis (rows) according to the index
        System.out.print("  "); 
        for (int j = 0; j < cols; j++) {
            System.out.print(j + " ");
        }
        System.out.println();
        
        //This will print out numbers for the y axis (columns) according to the index and then it goes printed out
        for (int i = 0; i < rows; i++) {
            System.out.print(i + " "); 
        for (int j = 0; j < cols; j++) {
            System.out.print(myArr[i][j] + " ");
        }
        System.out.println();
     }
    }


    // main function here itis being used to call everything back.
    public static void main(String[] args) {

    char[][] canvas = new char[5][10];

    Drawing.createCanvas(canvas);

    Drawing.addCharacter(canvas, '(', 4, 2);

    Drawing.addCharacter(canvas, ':', 5, 2);

    Drawing.printCanvas(canvas);
    }
}   
    
