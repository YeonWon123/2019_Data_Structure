#include <stdio.h>
#include <string.h>

struct student_record_node {
	struct student_record_node *next_;
	struct student_record_node *prev_;
	const char *name;
	unsigned int age;
};

void swap(struct student_record_node *node1, struct student_record_node *node2)
{
	struct student_record_node *ptr1, *ptr2;

	/* Swap the 'next_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->next_ ? node2 : node2->next_;
	ptr2 = node2 == node1->next_ ? node1 : node1->next_;
	node1->next_ = ptr1;
	node2->next_ = ptr2;
	/* Swap the 'prev_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->prev_ ? node2 : node2->prev_;
	ptr2 = node2 == node1->prev_ ? node1 : node1->prev_;
	node1->prev_ = ptr1;
	node2->prev_ = ptr2;
	/* Fix the links from other nodes. */
	if (node1->next_) node1->next_->prev_ = node1;
	if (node1->prev_) node1->prev_->next_ = node1;
	if (node2->next_) node2->next_->prev_ = node2;
	if (node2->prev_) node2->prev_->next_ = node2;
}

int compare_ages(const struct student_record_node *a,
	const struct student_record_node *b)
{
	return a->age < b->age ? -1 : a->age > b->age ? 1 : 0;
}

int compare_names(const struct student_record_node *a,
	const struct student_record_node *b)
{
	return strcmp(a->name, b->name);
}

void sort(struct student_record_node **recordsHead,
	int(*compare_fcn)(const struct student_record_node *,
		const struct student_record_node *))
{
	int swapped;
	struct student_record_node *ptr1;
	struct student_record_node *lptr = NULL;

	if (*recordsHead == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = *recordsHead;

		while (ptr1->next_ != lptr)
		{
			if (compare_fcn(ptr1, ptr1->next_) > 0)
			{
				printf("swapping (%s:%u <=> %s:%u)\n", ptr1->name, ptr1->age,
					ptr1->next_->name, ptr1->next_->age);
				swap(ptr1, ptr1->next_);
				if (ptr1 == *recordsHead)
				{
					/* ptr1 is now the second node. */
					(*recordsHead) = ptr1->prev_;
				}
				swapped = 1;
			}
			else
			{
				ptr1 = ptr1->next_;
			}
		}
		lptr = ptr1;
	} while (swapped);
}

void dump(const struct student_record_node *students)
{
	const struct student_record_node *prev_ = NULL;
	unsigned int pos = 0;

	while (students)
	{
		if (students->prev_ != prev_)
		{
			printf("[%u] ** Bad prev_ link!\n", pos);
		}
		printf("[%u] %s:%u\n", pos, students->name, students->age);
		pos++;
		prev_ = students;
		students = students->next_;
	}
}

int main(void)
{
	static struct student_record_node testdata[] =
	{
		{ testdata + 1, NULL, "susan", 20 },
		{ testdata + 2, testdata + 0, "bill", 21 },
		{ testdata + 3, testdata + 1, "joe", 18 },
		{ testdata + 4, testdata + 2, "tom", 19 },
		{ NULL, testdata + 3, "karen", 21 },
	};
	struct student_record_node *students = testdata;

	puts("Original order:");
	dump(students);
	puts("By name:");
	sort(&students, compare_names);
	dump(students);
	puts("By age:");
	sort(&students, compare_ages);
	dump(students);
	return 0;
}