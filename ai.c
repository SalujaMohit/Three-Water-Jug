#include<stdio.h>
#include<stdbool.h>

// Node is created containing contents of 8,5,3 litre jugs and also id of parent.

struct node
{
	int state[3];
	int pid;	
};

typedef struct node node;
node queue[5000];
int count;
int current;
int final_index;

// Function to insert a node in queue.

void insert(node x)
{
	int i;
	bool present = false;
	for(i=0;i<count;i++)
	{
		if(queue[i].state[0] == x.state[0] && queue[i].state[1] == x.state[1] && queue[i].state[2] == x.state[2])
		{
			present = true;
			break;
		}
	}

	if(present==false){
		queue[count].state[0] = x.state[0];
		queue[count].state[1] = x.state[1];
		queue[count].state[2] = x.state[2];
		queue[count].pid = current;
		count++;
	}
	
}

// Node is checked if it is goal state.

bool check()
{
	
	if( queue[current].state[0]==4 || queue[current].state[1]==4)
	{   
		final_index = current;
		return false;
	}
	else
	{
		return true;
	}
}

// Transferring water from eight litre jug to five litre jug.

void from_eight_to_five(node x)
{
	if(x.state[0]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[0]>=0 && x.state[0]<=8 && x.state[1]>=0 && x.state[1]<=5)
	{
		x.state[0] = x.state[0] - 1;
		x.state[1] = x.state[1] + 1; 
	}

	    x.state[0] = x.state[0] + 1;
		x.state[1] = x.state[1] - 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}

}
}

// Transferring water from eight litre jug to three litre jug.

void from_eight_to_three(node x)
{
	if(x.state[0]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[0]>=0 && x.state[0]<=8 && x.state[2]>=0 && x.state[2]<=3)
	{
		x.state[0] = x.state[0] - 1;
		x.state[2] = x.state[2] + 1; 
	}

	x.state[0] = x.state[0] + 1;
	x.state[2] = x.state[2] - 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}

}
}

// Transferring water from five litre jug to eight litre jug.

void from_five_to_eight(node x)
{
	if(x.state[1]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[0]>=0 && x.state[0]<=8 && x.state[1]>=0 && x.state[1]<=5)
	{
		x.state[0] = x.state[0] + 1;
		x.state[1] = x.state[1] - 1; 
	}

	x.state[0] = x.state[0] - 1;
	x.state[1] = x.state[1] + 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}

}
}

// Transferring water from five litre jug to three litre jug.

void from_five_to_three(node x)
{
	if(x.state[1]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[2]>=0 && x.state[2]<=3 && x.state[1]>=0 && x.state[1]<=5)
	{
		x.state[2] = x.state[2] + 1;
		x.state[1] = x.state[1] - 1; 
	}
     
     x.state[2] = x.state[2] - 1;
	 x.state[1] = x.state[1] + 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}

}
}

// Transferring water from three litre jug to eight litre jug.

void from_three_to_eight(node x)
{
	if(x.state[2]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[0]>=0 && x.state[0]<=8 && x.state[2]>=0 && x.state[2]<=3)
	{
		x.state[0] = x.state[0] + 1;
		x.state[2] = x.state[2] - 1; 
	}

    x.state[0] = x.state[0] - 1;
	x.state[2] = x.state[2] + 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}

}
}

// Transferring water from three litre jug to five litre jug.

void from_three_to_five(node x)
{
	
	if(x.state[2]!=0){
	node temp;
	temp.state[0] = x.state[0];
	temp.state[1] = x.state[1];
	temp.state[2] = x.state[2];
	
	while(x.state[2]>=0 && x.state[2]<=3 && x.state[1]>=0 && x.state[1]<=5)
	{
		x.state[2] = x.state[2] - 1;
		x.state[1] = x.state[1] + 1; 
	}

    x.state[2] = x.state[2] + 1;
	x.state[1] = x.state[1] - 1;

	if(temp.state[0] == x.state[0] && temp.state[1] == x.state[1] && temp.state[2] == x.state[2])
	{

	}
	else
	{
		insert(x);
	}
}

}

// Function to create child nodes.

void generate(node x)
{
	node a,b,c,d,e,f;
	a.state[0] = x.state[0];
	a.state[1] = x.state[1];
	a.state[2] = x.state[2];

	b.state[0] = x.state[0];
	b.state[1] = x.state[1];
	b.state[2] = x.state[2];

	c.state[0] = x.state[0];
	c.state[1] = x.state[1];
	c.state[2] = x.state[2];

	d.state[0] = x.state[0];
	d.state[1] = x.state[1];
	d.state[2] = x.state[2];

	e.state[0] = x.state[0];
	e.state[1] = x.state[1];
	e.state[2] = x.state[2];

	f.state[0] = x.state[0];
	f.state[1] = x.state[1];
	f.state[2] = x.state[2];

	from_eight_to_five(a);
	from_eight_to_three(b);
	from_five_to_eight(c);
	from_five_to_three(d);
	from_three_to_eight(e);
	from_three_to_five(f);


}

// Main function

int main()
{
	node a,b;
	queue[0].state[0] = 8;
	queue[0].state[1] = 0;
	queue[0].state[2] = 0;
	queue[0].pid = -1;

	count = 1;
	current = 0;
	bool status = true;

	while(status)
	{
		generate(queue[current]);
		current = current + 1;
		status = check();

	}
  
    int index = final_index;

	while(index!=-1)
	{
       
       printf("%d\t%d\t%d\n",queue[index].state[0],queue[index].state[1],queue[index].state[2]);
       index = queue[index].pid;

	}
	return 0;
}














