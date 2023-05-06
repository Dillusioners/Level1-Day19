/*
 * Author - Debag101
 * Purpose - Rock Paper Scissor game
 * Date - 6 5 2023
 */
import java.util.Random;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class RPS {

    //String[] array to store the gameplay options
    static String[] Options = { "Rock", "Paper", "Scissors" };
    //Creating random obj
    static Random rand = new Random();
    //Fixing max tries
    static final int maxTries = 5;
    //Keeping record of botPoints and userPoints
    static int BotPoints = 0, UserPoints = 0;

    //Display Method
    public static void display() {
        System.out.println("########################");
        System.out.println(" ROCK - PAPER - SCISSORS");
        System.out.println("########################");
    }

    //The play method
    public static void play()throws IOException {

        BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
        int i = 1;
        //Input Message
        String str = "Enter your choice =>\n1.Rock\n2.Paper\n3.Scissors";
        //Running till i reaches max tries
        while (i <= maxTries) {
            try {
                //Giving msg to user
                System.out.println(str);
                //Getting input
                int choice = Integer.parseInt(rd.readLine());
                //Getting random bot choice
                int botChoice = rand.nextInt(1, 4);
                //If choice is invalid
                if (choice < 1 || choice > 3)
                    System.out.println("(-)Not a choice !");
                //If it is a draw
                else if (choice == botChoice) {
                    System.out.printf("Opponent chose %s, You chose %s! Its a draw\n\n", Options[botChoice],
                            Options[choice]);
                    i++;
                } else {
                    //Working over options : 
                    
                    if (choice == 1 && botChoice == 2) {//choice = Rock, bot = Paper
                        System.out.printf("Opponent chose %s, You chose %s! You lost this round!\n", Options[botChoice],
                                Options[choice]);
                        BotPoints++;
                        i++;
                    } else if (choice == 1 && botChoice == 3) {//choice = Rock, bot = Scissors
                        System.out.printf("Opponent chose %s, You chose %s! You win this round\n", Options[botChoice],
                                Options[choice]);
                        UserPoints++;
                        i++;
                    } else if (choice == 2 && botChoice == 1) {//choice = Paper, bot = Rock
                        System.out.printf("Opponent chose %s, You chose %s! You win this round\n", Options[botChoice],
                                Options[choice]);
                        UserPoints++;
                        i++;
                    } else if (choice == 2 && botChoice == 3) {//choice = Paper, bot = Scissor
                        System.out.printf("Opponent chose %s, You chose %s! You lose this round\n", Options[botChoice],
                                Options[choice]);
                        BotPoints++;
                        i++;
                    } else if (choice == 3 && botChoice == 1) {//choice = Scissor, bot = Rock
                        System.out.printf("Opponent chose %s, You chose %s! You Lose this round\n", Options[botChoice],
                                Options[choice]);
                        BotPoints++;
                        i++;
                    } else {//choice = Scissor, bot = paper
                        System.out.printf("Opponent chose %s, You chose %s! You won this round\n", Options[botChoice],
                                Options[choice]);
                        UserPoints++;
                        i++;
                    }
                }
            } catch (Exception NumberFormatException) {//Catching errors
                System.out.println("(-)Not a choice ! Input the Serial number");
            }
        }
    
    }

    public static void main(String[] args) throws IOException {//Main method

        display();
        play();

        if (BotPoints > UserPoints)//Checking who won
            System.out.println("The bot wins!");
        else if (UserPoints > BotPoints)
            System.out.println("You Win !");
        else
            System.out.println("DRAW GAME !");

    }
}
