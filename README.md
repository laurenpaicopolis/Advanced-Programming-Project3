The program I created is a VTMountain Guessing Game. Basically, the user is given four criteria to rank their
preferences on from 1 to 4. These criteria are the distance the mountain is from UVM, season pass price at the mountain,
the total number of green trails at the mountain, and the total number of black trails. After they pick their preferences
from 1-4 on each of the criteria listed above, they are able to enter in how many Vermont mountains they would like to try
and guess between. They then can guess which Vermont ski mountains meet their criteria, and earn points based on how
many guesses it took them to guess correctly. In addition, the user can save their score if it is a high score, and
are able to compare their own score to the high score of the entire game. The user also has the opportunity to enter
in their name and whether they are a skier or a snowboarder which gets saved with their score if it is a high score.
In addition, after the user is done playing, they are allowed to become a critic. For my project's purpose, the only
critic they are allowed to become is a game critic, so they can review the VTMountain Guessing Game. The user is
allowed to enter how many stars out of 5 they would give and a review of the game. This is then written
and saved to a csv file.

The parent class is the Player class, and represents a generic player of a game. It includes
a high score, points, and a player name which the child class SkierSnowboarder inherits, along with the setters and getters for
those fields. It also includes a calculate high score function, which the SkierSnowboarder uses in the VTMountain
Guessing game. The child class is the SkierSnowboarder class and represents a skier or snowboarder
going to the mountain. The added fields are all of the vectors holding the Vermont mountains the user is
guessing between, the user's preferences based on criteria (1-4), and counters to keep track of how many guesses the user has used.
There is also a string which holds the player's winter sport and a vector to hold previous random numbers already generated
for Vermont mountains which the user guesses between. The SkierSnowboarder class has multiple added methods which generates
the VTMountains the user can guess between, allows the user to enter in guesses, prints the mountains the user can guess between,
and calculates whether the user's mountain guess is correct based on the category. The component class is VTMountain. This
class holds all of the data on each Vermont ski mountain, which allows the SkierSnowboarder class to use to compare
the user guesses and preferences for each category to the actual mountains in Vermont. The unrelated class is the
critic class. This class allows the user to enter in a review for the VTMountain Guessing Game after they are done playing.
The critic class uses the same name entered in from the SkierSnowboarder class, and this field is actually inherited from
SkierSnowboarder parent class, Player.