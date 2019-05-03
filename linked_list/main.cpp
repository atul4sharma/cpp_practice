
#include <iostream>


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
    if( *head == NULL or (*head)->next == NULL )
        return;

    ListNode * current = *head;
    ListNode * next    = NULL;
    ListNode * prev    = NULL;

    while( current != NULL )
    {
        next = current->next;
        current->next = prev;

        prev    = current;
        current = next;
    }
    
    *head = prev;
}

auto reverse_list(ListNode ** head, int A, int B)
    -> void
{
    if( *head == NULL or (*head)->next == NULL )
        return;

    auto counter = int{0};
    ListNode * current = *head;
    ListNode * next    = NULL;
    ListNode * prev    = NULL;
    
    do
    {
        next    = current->next;
        prev    = current;
        current = next;

        ++counter;
    } while( counter < A-1);

    ListNode * starting = prev;
    ListNode * ending = current;

    while( counter < B-1 and current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev    = current;
        current = next;
        ++counter;
    }

    next           = current->next;
    current->next  = prev;
    starting->next = current;
    ending->next   = next;

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
        a = head;
        b = head;
        increment_by(&a, i);
        increment_by(&b, n-i-1);
        //std::cout << "a -> " << a->val << " b -> " << b->val << "\n";
        a->val = b->val - a->val;
        ++i;
    }
    return head;
}


int main()
{

    ListNode * head = NULL;
    create_list(&head, {1,2,3,4,5,6,7,8,9,10});
    print_list(std::cout, head);
    int n = count_elements(head);
    //increment_by(&head, 2);
    calculate_difference(head, n);
    print_list(std::cout, head);

}
