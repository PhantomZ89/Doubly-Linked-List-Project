# Doubly-Linked-List-Project
Project based on an Algorithm and Data Structure assignment that was given in school.


    1. If there are zero elements in the list, the list is said to be empty.
    2. Each element is stored in an instance of the Double_node<Type> class.
    3. At all times, the head and tail pointers store the addresses of the head and tail sentinel nodes, respectively.
    4. The previous pointer of the head sentinel always points to nullptr.
    5. The next pointer of the tail sentinel always points to nullptr.
    6. If the list is empty, the next pointer of the head sentinel node is assigned the address of the tail sentinel; otherwise, the next        pointer of the head sentinel node is assigned the address of the first node in the linked list (the front node).
    7. If the list is empty, the previous pointer of the tail sentinel node is assigned the address of the head sentinel; otherwise, the previous pointer of the tail sentinel node is assigned the address of the last node in the linked list (the back node).
    8. The next pointer of the kth node (1 ≤ k < n) stores the address of the (k + 1)st node, the next pointer of the nth is assigned to the address of the tail sentinel.
    9. The previous pointer of the kth node (1 < k ≤ n) stores the address of the (k − 1)st node, and the previous pointer of the first node is assigned the address of the head sentinel.

Functions:
   
        int size() const;
            Returns the number of items in the list.
        bool empty() const;
            Returns true if the list is empty, false otherwise.
        Type front() const;
            Retrieves the object stored in the node pointed to by the next pointer of the head sentinel. This function throws a underflow if the list is empty.
        Type back() const;
            Retrieves the object stored in the node pointed to by the previous pointer of the tail sentinel. This function throws a underflow if the list is empty.
        Double_sentinel_list<Type>::Double_node *begin() const;
            Returns the address stored by the next pointer of the head sentinel node.
        Double_sentinel_list<Type>::Double_node *end() const;
            Returns the address of the tail sentinel node.
        Double_sentinel_list<Type>::Double_node *revbegin() const;
            Returns the address stored by the previous pointer of the tail sentinel node.
        Double_sentinel_list<Type>::Double_node *revend() const;
            Returns the address of the head sentinel node.
        Double_sentinel_list<Type>::Double_node find( Type const & ) const;
            Returns the address of the first node in the linked list storing a value equal to the argument; if none is found, return end().
        int count( Type const & ) const;
            Returns the number of nodes in the linked list storing a value equal to the argument.       
        void swap( Double_sentinel_list &list );
            The swap function swaps all the member variables of this linked list with those of the argument list.
        Double_sentinel_list &operator=( Double_sentinel_list const &rhs );
            The assignment operator makes a copy of the argument (the right-hand side of the assignment) and then swaps the member variables of this node doubly linked sentinel list those of the copy.
        Double_sentinel_list &operator=( Double_sentinel_list &&rhs );
            The move operator moves the nodes in the argument (the right-hand side of the assignment) linked list to this linked list, changing the argument linked list into an empty list.
        void push_front( Type const &new_value );
            Creates a new Double_node<Type> storing the argument new_value, the next pointer of which is set to the next pointer of the sentinel and the previous pointer is set to point to the sentinel. The next pointer of the sentinel and the previous pointer of what was the first node are set to this new node.
        void push_back( Type const &new_value );
            Similar to push_front, this places a new node at the back of the list storing the argument new_value.
        void pop_front();
            Delete the first non-sentinel node at the front of the linked list and update the previous and next pointers of any other node (including possibly the sentinels) within the list as necessary. Throw an underflow exception if the list is empty.
        void pop_back();
            Similar to pop_front, delete the last non-sentinel node in the list. This function throws a underflow if the list is empty.
        int erase( Type const &value );
            Delete all the nodes in the linked list that have a value equal to the argument value (use == to to test for equality with the retrieved element). Update the previous and next pointers of any other node (including possibly the sentinels) within the list. Return the number of nodes that were deleted.
