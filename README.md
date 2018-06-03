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
