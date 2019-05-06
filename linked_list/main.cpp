
#include <iostream>
#include <cmath>


struct ListNode 
{
    explicit ListNode(int value)
        :val{value}
    {}

    int        val{};
    ListNode * next{NULL};
};


auto print_list(std::ostream & out, ListNode const * head)
    -> std::ostream &
{
    auto current = head;
    while( current )
    {
        out << current->val << "->";
        current = current->next;
    }
    out << "\n";
    return out;
}


auto append(ListNode ** head, int item)
    -> void
{
    ListNode * new_node = new ListNode{item};
    if( *head == NULL )
    {
        *head = new_node;
        return;
    }

    ListNode * current = *head;
    while(current->next != NULL)
    {
        current = current->next;

    }
    current->next = new_node;
}

auto create_list(ListNode ** start, std::initializer_list<int> const & l)
    -> int 
{
    auto counter = int{0};
    for(auto const item : l)
    {
       append(start, item);
       ++counter;
    }
    return counter;
}

auto delete_list(ListNode ** head)
    -> void
{
    if( *head == NULL )
        return;

    ListNode * temp = (*head)->next;
    delete *head;
    *head = NULL;
    delete_list(&temp);
}

auto reverse_list(ListNode ** head)
    -> void
{
    if( *head == NULL )
        return;
    ListNode * first = *head;
    ListNode * rest  = first->next;

    if( rest == NULL )
        return;

    reverse_list(&rest);
    (first->next)->next = first;
    first->next = NULL;

    *head = rest;
}

auto count_elements(ListNode * head)
    -> int
{
    int counter = 0;
    ListNode * current = head;
    while( current )
    {
        ++counter;
        current = current->next;
    }
    return counter;
}

auto increment_by(ListNode ** A, int n)
    -> void
{
    while( n )
    {
        *A = (*A)->next;
        --n;
    }
}

auto calculate_difference(ListNode * head, int n)
    -> ListNode *
{
    if(n <= 1)
        return head;

    // b - a
    ListNode * a = head;
    ListNode * b = head;
    int half = n/2;
    int i = 0;

    while(i < half)
    {
        b = a;
        increment_by(&b, n - (i*2)-1);
        a->val = b->val - a->val;
        increment_by(&a, 1);
        ++i;
    }
    return head;
}

auto reverse_after(ListNode * head, int n)
    -> ListNode *
{
    if( n <= 1)
        return head;

    ListNode * a = head;
    increment_by(&a, n-1);
    ListNode * b = a;
    a = a->next;
    reverse_list(&a);
    b->next = a;

    return a;

}

auto calc_difference(ListNode * head)
    -> void
{
    if(head == NULL or head->next == NULL )
        return;

    int n = count_elements(head);
    if( n == 2 )
    {
        head->val = head->next->val - head->val;
        return;
    }
    int half = std::ceil(n/2.0);
    ListNode * first  = head;
    ListNode * second = reverse_after(head, half);

    while(second != NULL)
    {
        first->val = second->val - first->val;
        first  = first->next;
        second = second->next;
    }
    reverse_after(head, half);
}

int main()
{

    ListNode * head = NULL;
    //create_list(&head, {1,2,3,4,5,6,7,8,9,10});
    create_list(&head, {1,5});
    print_list(std::cout, head);
    int n = count_elements(head);
    //increment_by(&head, 2);
    //calculate_difference(head, n);
    //reverse_list(&head);
    //int half = std::ceil(n/2.0);
    //reverse_after(head, half);
    calc_difference(head);
    print_list(std::cout, head);

}
