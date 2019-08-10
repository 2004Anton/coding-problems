/*
PROBLEM 1;

Out of Place
============

Feeling ambitious, Farmer John plans to attempt something that never seems to go quite right: he wants to 
take a photograph of his entire herd of cows.

To make the photograph look nice, he wants the cows to line up in a single row from shortest to tallest.
 Unfortunately, right after he has the cows line up this way, Bessie the cow, always the troublemaker, steps out
 of line and re-inserts herself at some other location in the lineup!

Farmer John would like to swap pairs of cows so the entire herd is again lined up properly. Please help him
 determine the minimum number of swaps he needs to make between pairs of cows in order to achieve this
 goal.

INPUT FORMAT:

The first line of input contains N (2≤N≤100). The next N lines describe the heights of the cows as they are lined
 up after Bessie makes her move. Each cow height is an integer in the range 1…1,000,000. Cows may have
 the same height.

OUTPUT FORMAT:

Please output the minimum number of times Farmer John needs to swap pairs of cows in order to achieve a
 proper ordering. Swaps do not necessarily need to involve adjacent cows in the ordering.

SAMPLE INPUT:

6
2
4
7
7
9
3

SAMPLE OUTPUT:

3

In this example, Bessie is clearly the cow of height 3. FJ return the cows to sorted order using three swaps as
 described below:

2 4 7 7 9 3 - Original Lineup
2 4 7 7 3 9 - Swap the last two cows
2 4 3 7 7 9 - Swap the first 7 and 3
2 3 4 7 7 9 - Swap 4 and 3

PROBLEM 2:

Bovine Bones
============

Bessie loves board games and role-playing games so she persuaded
Farmer John to drive her to the hobby shop where she purchased three
dice for rolling. These fair dice have S1, S2, and S3 sides
respectively (2 <= S1 <= 20; 2 <= S2 <= 20; 2 <= S3 <= 40).

Bessie rolls and rolls and rolls trying to figure out which three-dice
sum appears most often.

Given the number of sides on each of the three dice, determine which
three-dice sum appears most frequently. If more than one sum can
appear most frequently, report the smallest such sum.

PROBLEM NAME: bones

INPUT FORMAT:

* Line 1: Three space-separated integers: S1, S2, and S3

SAMPLE INPUT:

3 2 3

OUTPUT FORMAT:

* Line 1: The smallest integer sum that appears most frequently when
        the dice are rolled in every possible combination.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

Here are all the possible outcomes.
1 1 1 -> 3  1 2 1 -> 4  2 1 1 -> 4  2 2 1 -> 5  3 1 1 -> 5  3 2 1 -> 6
1 1 2 -> 4  1 2 2 -> 5  2 1 2 -> 5  2 2 2 -> 6  3 1 2 -> 6  3 2 2 -> 7
1 1 3 -> 5  1 2 3 -> 6  2 1 3 -> 6  2 2 3 -> 7  3 1 3 -> 7  3 2 3 -> 8

Both 5 and 6 appear most frequently (five times each), so 5 is the answer.



PROBLEM 3: 

Bookshelf 2
===========

Farmer John recently bought another bookshelf for the cow library,
but the shelf is getting filled up quite quickly, and now the only
available space is at the top.

FJ has N cows (1 <= N <= 20) each with some height of H_i (1 <= H_i
<= 1,000,000 - these are very tall cows). The bookshelf has a height
of B (1 <= B <= S, where S is the sum of the heights of all cows).

To reach the top of the bookshelf, one or more of the cows can stand
on top of each other in a stack, so that their total height is the
sum of each of their individual heights. This total height must be
no less than the height of the bookshelf in order for the cows to
reach the top.

Since a taller stack of cows than necessary can be dangerous, your
job is to find the set of cows that produces a stack of the smallest
height possible such that the stack can reach the bookshelf. Your
program should print the minimal 'excess' height between the optimal
stack of cows and the bookshelf.

PROBLEM NAME: shelf2

INPUT FORMAT:

* Line 1: Two space-separated integers: N and B

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

5 16
3
1
3
5
6

OUTPUT FORMAT:

* Line 1: A single integer representing the (non-negative) difference
        between the total height of the optimal set of cows and the
        height of the shelf.

SAMPLE OUTPUT:

1

OUTPUT DETAILS:

Here we use cows 1, 3, 4, and 5, for a total height of 3 + 3 + 5 + 6 = 17.
It is not possible to obtain a total height of 16, so the answer is 1.
SOURCE: http://tjsct.wikidot.com/usaco-dec07-bronze


PROBLEM 4:

Catch That Cow
==============

Farmer John has been informed of the location of a fugitive cow 
and wants to catch her immediately. He starts at a point N 
(0 <= N <= 100,000) on a number line and the cow is at a point K 
(0 <= K <= 100,000) on the same number line. Farmer John has 
two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 
or X + 1 in a single minute

* Teleporting: FJ can move from any point X to the point 
2 * X in a single minute.

If the cow, unaware of its pursuit, does not move at all, 
how long does it take for Farmer John to retrieve it?

PROBLEM NAME: catchcow

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

SAMPLE INPUT:

5 17

OUTPUT FORMAT:

* Line 1: The least amount of time, in minutes, it takes for 
	Farmer John to catch the fugitive cow.


SAMPLE OUTPUT:

4

OUTPUT DETAILS:

The fastest way for Farmer John to reach the fugitive cow is to move 
along the following path: 5-10-9-18-17, which takes 4 minutes.
*/
public class problems {
	public int problem1(int num, int[] cows) {
		int ans = 0;
		int[] unsortedCows = copy(cows);
		bubbleSort(cows);
		boolean b = true;
		while(!sorted(unsortedCows)) {
			int s  = -1;
			for(int i = 0; i < unsortedCows.length; i++) {
				if(unsortedCows[i] != cows[i] && s == -1) {
					s = i;
				}
				else if(s != -1) {
					if(unsortedCows[i] == cows[s]) {
						swap(unsortedCows,s,i);
						s = -1;
						ans++;
					}
				}
			}
		}
		return ans;
		
	}
	public void swap(int[] nums, int pos1, int pos2) {
		int temp = nums[pos1];
		nums[pos1] = nums[pos2];
		nums[pos2] = temp;
	}
	public int[] copy(int[] nums) {
		int[] ans = new int[nums.length];
		for(int i= 0; i < nums.length; i++) {
			ans[i] = nums[i];
		}
		return ans;
	}
	public void print(int[] nums) {
		for(int i = 0; i < nums.length; i++) {
			System.out.print(nums[i] + ", ");
		}
		System.out.println();
	}
	public boolean sorted(int[] nums) {
		for(int i = 0; i < nums.length-1; i++) {
			if(nums[i] > nums[i+1])return false;
		}
		return true;
	}
	public void bubble(int[] nums) {
		for(int i = 0; i < nums.length-1; i++) {
			if(nums[i] > nums[i+1]) {
				int temp = nums[i+1];
				nums[i+1] = nums[i];
				nums[i] = temp;
			}
		}
	}
	public int[] bubbleSort(int[] nums) {
		boolean b = true;
		while(b) {
			bubble(nums);
			int counter = 0;
			for(int i =0; i < nums.length-1; i++) {
				if(nums[i] > nums[i+1]) {
					counter = 1;
				}
			}
			if(counter == 0) {
				b = false;
			}
		}
		return nums;
	}
	public int problem2(int dice1, int dice2, int dice3) {
		double d1 = ((double)addTo(dice1))/((double) (dice1));
		double d2 = ((double)addTo(dice2))/((double) (dice2));
		double d3 = ((double)addTo(dice3))/((double) (dice3));
		
		return (int) Math.floor(d1+d2+d3);
	}
	public int addTo(int num) {
		return (1+num)*num/2;
	}
	public int problem3(int numCows, int shelfHeight, int[] cows) {
		int[] unsCows = copy(cows);
		return findOptions(0,0,shelfHeight,cows);
	}
	public int findOptions(int index, int currHeight, int shelfHeight, int[] cows) {
		if(index == cows.length-1) {
			if(cows[index] + currHeight-shelfHeight > 0) {
				if(currHeight-shelfHeight > 0) {
					return currHeight-shelfHeight;
				}
				return cows[index]+currHeight-shelfHeight;
			}
			return Integer.MAX_VALUE;
		}
		return Math.min(findOptions(index+1, currHeight+cows[index], shelfHeight, cows),findOptions(index+1, currHeight,shelfHeight,cows));
	}
	public int problem4(int JohnPos, int CowPos) {
		if(CowPos < JohnPos) {
			System.out.println("here");
			return JohnPos-CowPos;
		}
		return findClosestGoodDouble(0,JohnPos,CowPos);

	}
	public int findClosestGoodDouble(int mins, int JohnPos, int CowPos) {
		System.out.println("CowPos:" + CowPos + "Mins:" + mins);
		
		if(CowPos%2 == 1) {
			if(Math.abs(JohnPos-CowPos) < Math.abs(JohnPos-((CowPos+1)/2)) || Math.abs(JohnPos-CowPos) < Math.abs(JohnPos-((CowPos-1)/2))) {
				return Math.abs(JohnPos-CowPos) + mins;
			}
			return Math.min(findClosestGoodDouble(mins+2, JohnPos, (CowPos+1)/2), findClosestGoodDouble(mins+2, JohnPos, (CowPos-1)/2));
		}
		else {
			if(Math.abs(JohnPos-CowPos) < Math.abs(JohnPos-((CowPos)/2))) {
				return Math.abs(JohnPos-CowPos) + mins;
			}
		}
		return findClosestGoodDouble(mins+1,JohnPos,CowPos/2);
	}
}
