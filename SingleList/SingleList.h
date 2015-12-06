#pragma once
typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;
void InitList(ListNode *pHead)
{
	pHead = NULL;
}
ListNode *BuyNode(DataType x)
{
    ListNode *p =NULL;
	p = (ListNode *)malloc(sizeof(ListNode)) ;
	if(NULL == p)
	{
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void PushBack(ListNode*& pHead,DataType x)
{
	if(pHead == NULL)
	{
		pHead = BuyNode(x);
	}
	else
	{
		ListNode *tail = pHead;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);

	}
}
void PrintList(ListNode *pHead)
{
	ListNode *tmp = pHead;
	while(tmp != NULL)
	{
		printf("%d->",tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
void PopFront(ListNode *&pHead)
{
	//������ʲô��û��
	if(pHead == NULL)
	{
		printf("nothing to pop\n");
		return;
	}
	//������ֻ��һ���ڵ�
	else if(pHead->next == NULL)
	{
		pHead = NULL;
	}
	//��������һ�����Ͻ��
	else
	{	
		ListNode *tmp = pHead;
		pHead = pHead->next;
		free(tmp);
		tmp =NULL;
		return;
	}
}
ListNode *Find(ListNode *pHead,DataType x)
{	
		ListNode *tmp = pHead;
		while(tmp != NULL)
		{
			if(tmp->data == x)
			{
				return tmp;
			}
				tmp = tmp->next;
		}
	printf("dont have this num\n");
	return NULL;
}
void Erase(ListNode *&pHead,ListNode *pos)
{
	assert(pos);
	//ɾ������ͷ���
	if(pos == pHead)
	{
		pHead = pHead->next;
		free(pos);
		return;
	}
	else
	{
		ListNode *tmp = pHead;
		while(tmp != NULL)
		{
			if(tmp->next == pos)
			{
				tmp->next = pos->next;
				free(pos);
				return;
			}
			tmp = tmp->next;
		}
	}
	printf("dont have this num\n");
}
void Insert(ListNode *pHead,ListNode *pos,DataType x)//��pos�����
{
	assert(pos);
	ListNode *tmp = pos->next;
	ListNode *cur = BuyNode(x);
	cur->next = tmp;
	pos->next = cur;
}
void Remove(ListNode *&pHead,DataType x)
{
	ListNode* ret = Find(pHead, x);
	if (ret)
	{
		Erase(pHead, ret);
	}	
}
ListNode *Reverse(ListNode *&pHead)
{
	ListNode *newHead = NULL,*cur = pHead;
	while(cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;

		tmp->next = newHead;
		newHead = tmp;
	}
	return newHead;
}
void PrintReverse(ListNode *pHead)
{
        
        if(pHead)
        {
            if(pHead->next)
                {
                    PrintReverse(pHead->next);
                }
               printf("%d->",pHead->data);	
        }
	
}
ListNode *JosephCycle(ListNode *pHead,int x)
{
	if(pHead == NULL)
	{
		printf("nothing in list");
		return NULL;
	}
	ListNode *cur = pHead;
	//�ɻ�
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = pHead;
	//	��ʼɾ
	cur = pHead;
	while(1)
	{
		if(cur->next != cur)
		{	
			int count = x;
			while(--count)
			{
				cur = cur->next;
			}
			//��ɾcur������û�ж���cur��ǰ����㣬���Խ�cur��һ������ֵ����cur����ɾ��һ����㼴��
			cur->data = cur->next->data;
			ListNode *tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
		}
		else
		{
			cur->next = NULL;//�⻷����ô�ӡ��ʱ��ͣ��������
			return cur;

		}
	}
}
void BubbleSort(ListNode *pHead)
{
	if(pHead == NULL || pHead->next == NULL)
	{
		printf("cant sort!\n");
		return;
	}
	ListNode *cur = pHead->next,*prev = pHead,*tail = NULL;
	int flag;
	while(tail != pHead)
	{			
			while(cur != tail)
			{
				if(prev->data > cur->data)
				{
					DataType tmp = prev->data;
					prev->data = cur->data;
					cur->data = tmp;

					flag = 1;
				}
				prev = cur;
				cur = cur->next;
			}
			if(flag = 0)
			{
				return;
			}
			tail = prev;
			cur = pHead->next;
			prev = pHead;
			flag = 0;
	}
	return;
}

ListNode *MergeList(ListNode *pHead1,ListNode* pHead2)
{
	ListNode *cur1 = pHead1,*cur2 = pHead2;
	ListNode *newHead = BuyNode(0);
	ListNode *cur = newHead;
	if((pHead1 == NULL) && (pHead2 == NULL))
	{
		printf("two empty list\n");
		return NULL;
	}
	else if(pHead1 == NULL)
	{
		return pHead2;
	}
	else if(pHead2 == NULL)
	{
		return pHead1;
	}

	while(cur1 && cur2)
	{
		if(cur1->data < cur2->data)
		{
			cur->next = cur1;
			cur = cur->next;
			cur1 = cur1->next;
			
		}
		else
		{
			cur->next = cur2;
			cur2 = cur2->next;
			cur = cur->next;
		}
	}
	cur->next = (cur1 != NULL)?cur1:cur2;
	
	ListNode* tmp = newHead;
	newHead = newHead->next;
	free(tmp);
	return newHead;

}
ListNode* FindTailnNode(ListNode* pHead,int k)//�ҵ�����K����㣬ֻ����һ��
{
	 ListNode *fast = pHead;
	 ListNode* slow =pHead;
	 while(--k)
	 {
		 if(fast->next != NULL)
		 {
			fast = fast->next;
		 }
		 else
		 {
			 printf("dont have this node/n");
			 return NULL;
		 }
	 }
	 while(fast->next != NULL)
	 {
		 fast = fast->next;
		 slow = slow->next;
	 }
	 return slow;
}
ListNode *IsLoop(ListNode *pHead)//�ж������Ƿ��л������л���ֱ�ӷ��ؿ���ָ��������
{

   ListNode *fast = pHead,*slow = pHead;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
	    if(fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}
int Cyclelength(ListNode *pHead,ListNode *meet)
{
	ListNode *cur = meet;
	int count = 1;
	while(cur->next != meet)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
ListNode *CycleEnter(ListNode *pHead,int len)
{
	ListNode *fast = pHead,*slow = pHead;
	int count = len;
	while(count--)
	{
		fast = fast->next;
	}
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
ListNode *CycleEnter2(ListNode *pHead,ListNode *meet)
{
	ListNode *cur1 = pHead,*cur2 = meet;
	while(cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}
bool IsIntersect(ListNode *pHead1,ListNode* pHead2)
 {
     ListNode *fast = pHead1,*slow = pHead2;
   
     if((fast == NULL) || (slow == NULL))
     {
         return false;
     }
     while(fast->next)
     {
         fast = fast->next;  
     }
     while(slow->next)
     {
         slow = slow->next;
     }
   
     if(fast == slow)
     {
         return true;
     }
     return false;
 } 
ListNode *EnterCross(ListNode *pHead1,ListNode* pHead2)
{
	ListNode *cur1 = pHead1,*cur2 = pHead2;
	int len1 = 0,len2 = 0;
	//�����������ĳ���
	while(cur1->next != NULL )
	{
		cur1 = cur1->next;
		len1++;
	}
	while(cur2->next != NULL )
	{
		cur2 = cur2->next;
		len2++;
	}
	
	if(len1 > len2)
	{
		int x = len1 - len2;
		ListNode *fast = pHead1,*slow = pHead2;
		while(x--)
		{
			fast = fast->next;
		}
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	else if(len1 < len2)
	{
		int x = len2 - len1;
		ListNode *fast = pHead2,*slow = pHead1;
		while(x--)
		{
			fast = fast->next;
		}
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	else
	{
		ListNode *fast = pHead1,*slow = pHead2;
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;

	}

}