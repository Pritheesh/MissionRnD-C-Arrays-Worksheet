/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student 
{
	char *name;
	int score;
};


void quick_sort(struct student *x, int first, int last)
{
	int pivot, j, i;
	struct student temp;
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (x[i].score >= x[pivot].score && i < last)
				i++;
			while (x[j].score < x[pivot].score)
				j--;
			if (i < j)
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quick_sort(x, first, j - 1);
		quick_sort(x, j + 1, last);

	}
}

struct student ** topKStudents(struct student * students, int len, int K)
{
	if (students == NULL || len < 0 || K <= 0)
		return NULL;
	if (K == 1)
	{
		struct student * top = &students[0];
		int maxIndex = 0;
		for (int i = 1; i < len; i++)
		if (top->score < students[i].score)
		{
			maxIndex = i;
			top = &students[i];
		}
		struct student ** top1 = (struct student **)malloc(sizeof(struct student));
		top1[0] = &students[maxIndex];
		return top1;
	}
	if (K > len)
		K = len;

	quick_sort(students, 0, len - 1);
	struct student ** top = (struct student **)malloc(sizeof(struct student) * K);
	for (int i = 0; i < K; i++)
	{
		top[i] = &students[i];
	}
	return top;
}