/*
 * We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.
 For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RIGHT 1
#define LEFT 2
//4 is a reserved holy bit
#define BANNED 8

typedef struct t_Asteroid Asteroid;
typedef struct t_Asteroid {
	int size;
	int direction;
	// Asteroid *prev;
	// Asteroid *next;
	// Look at this shit. Wasted space. We dont need pointers.
	// We have a chunk of allocated memory and offsets.
} Asteroid;

typedef struct {
	Asteroid *entry;
	int index;
} found_rec;

int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize);

//linked list functions
found_rec findNext(Asteroid *originalHead,int index, const int max_size);
found_rec findPrev(Asteroid *originalHead,int index);
//Do you even C if you don't use Macros where a function would make debugging so much easier?
#define ban(head, index) ((head)[index].direction |= BANNED)
#define isBanned(head, index) (((head)[index].direction & BANNED) == BANNED)


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
	int i; //for loop i
	int index = 0; //index for moving around the mapped memory
	int retSize = asteroidsSize;
	int *retArray;
	Asteroid *original_head;
	Asteroid *cur;
	Asteroid *next;
	Asteroid *prev;
	found_rec rec;

	if (asteroidsSize == 0) {
		printf("F off.\n");
		*returnSize = 0;
		return (int *)0x00;
	}

	//set up memory
	original_head = (Asteroid *) malloc(sizeof(Asteroid) * asteroidsSize);
	for (i = 0; i < asteroidsSize; i++) {
		if (i == 0) {
			cur = original_head;
			original_head->size = abs(asteroids[i]);
			original_head->direction = asteroids[i] >= 0 ? RIGHT : LEFT; //going positive or negative
		} else {
			cur += 1;
			cur->size = abs(asteroids[i]);
			cur->direction = asteroids[i] >= 0 ? RIGHT : LEFT;
		}
	}

	cur = original_head;

	//process!
	while (cur != NULL) { //maybe cur->next
		rec = findNext(original_head, index, asteroidsSize);
		next = rec.entry;
		if (!next) {
			cur = NULL;
			index++;
			//last item in the list, nothing to compare it to
			break;
		}

		if ( cur->direction == next->direction ) {
			//going the same direction, do nothing
			cur = next;
			index = rec.index;
			continue;
		}

		if ( (cur->direction & LEFT) == LEFT && (next->direction & RIGHT) == RIGHT) {
			//moving apart, do nothing
			cur = next;
			index = rec.index;
			continue;
		}

		//at this point, they must be colliding
		if (cur->size > next->size) {
			//left rock wins
			ban(original_head,rec.index);
			rec = findNext(original_head,rec.index,asteroidsSize);
			next = rec.entry;
			cur = next;
			index = rec.index;
			retSize--;
			//may leave cur on NULL, an end point
		} else if (cur->size < next->size) {
			//right rock wins
			ban(original_head,index);
			cur = rec.entry;
			index = rec.index;
			retSize--;
		} else {
			//both rocks are f
			ban(original_head,index);
			ban(original_head,rec.index);
			rec = findNext(original_head, rec.index,asteroidsSize);
			cur = rec.entry;
			index = rec.index;
			retSize -= 2;
		}

		//If a collision happened, back up a space to recalculate
	 	rec = findPrev(original_head, index);
		prev = rec.entry;
		if (cur != NULL && prev != NULL) {
			cur = prev;
			index = rec.index;
		}

	} //end while

	//repack return array
	retArray = (int *) malloc(sizeof(int) * retSize);
	cur = original_head;
	index = 0;
	if (isBanned(original_head,index)) {
		rec = findNext(original_head, index,asteroidsSize);
		cur = rec.entry;
		index = rec.index;
	}
	if (!cur) {
		//empty return list?
		*returnSize = 0;
		return retArray; //presumabily this is null?
	}
	for(i = 0; i < retSize; i++) {
		retArray[i] = cur->size;
		if (cur->direction == LEFT) {
			retArray[i] *= -1;
		}
		rec = findNext(original_head, index, asteroidsSize);
		cur = rec.entry;
		index = rec.index;
	}

	free(original_head);

	*returnSize = retSize;
	return retArray;
}

found_rec findNext(Asteroid *originalHead,int index, const int max_size) {
	found_rec ret_rec;
	ret_rec.index = 0;
	ret_rec.entry = NULL;
	while (index < max_size - 1) {
		index++;
		if (!isBanned(originalHead, index)) {
			ret_rec.index = index;
			ret_rec.entry = originalHead + index;
			break;
		}
	}
	return ret_rec;
}

found_rec findPrev(Asteroid *originalHead,int index) {
	found_rec ret_rec;
	ret_rec.index = 0;
	ret_rec.entry = NULL;
	while (index > 0) {
		index--;
		if(!isBanned(originalHead, index)) {
			ret_rec.index = index;
			ret_rec.entry = originalHead + index;
			break;
		}
	}
	return ret_rec;
}