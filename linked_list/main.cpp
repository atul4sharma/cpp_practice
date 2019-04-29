
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
    -> int
{
    auto counter = int{0};
    if( *head == NULL )
        return 0;

    ListNode * prev;
    while( *head != NULL )
    {
        prev = *head;
        *head = (*head)->next;
        delete prev;
        ++counter;
    }
    *head = NULL;
    return counter;
}

int main()
{
    ListNode * head = NULL;
    create_list(&head, {1,2,3,4,5,6,7,8});
    print_list(std::cout, head);
    delete_list(&head);
    print_list(std::cout, head);
}
