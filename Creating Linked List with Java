import java.io.*;

public class LinkedList {

	Node head; // head of list

	static class Node {

		int data;
		Node next;

		// Constructor
		Node(int d)
		{
			data = d;
			next = null;
		}
	}

	// Method to insert a new node
	public static LinkedList insert(LinkedList list,
									int data)
	{
		// Create a new node with given data
		Node new_node = new Node(data);
		new_node.next = null;

		if (list.head == null) {
			list.head = new_node;
		}
		else {
			// Else traverse till the last node
			// and insert the new_node there
			Node last = list.head;
			while (last.next != null) {
				last = last.next;
			}

			// Insert the new_node at last node
			last.next = new_node;
		}

		// Return the list by head
		return list;
	}

	// Method to print the LinkedList.
	public static void printList(LinkedList list)
	{
		Node currNode = list.head;

		System.out.print("LinkedList: ");

		// Traverse through the LinkedList
		while (currNode != null) {
			// Print the data at current node
			System.out.print(currNode.data + " ");

			// Go to next node
			currNode = currNode.next;
		}

		System.out.println();
	}

	// Method to delete a node in the LinkedList by POSITION
	public static LinkedList
	deleteAtPosition(LinkedList list, int index)
	{
		// Store head node
		Node currNode = list.head, prev = null;


		if (index == 0 && currNode != null) {
			list.head = currNode.next; // Changed head

			// Display the message
			System.out.println(
				index + " position element deleted");

			// Return the updated List
			return list;
		}

	
		int counter = 0;

		while (currNode != null) {

			if (counter == index) {
				// Since the currNode is the required
				// position Unlink currNode from linked list
				prev.next = currNode.next;

				// Display the message
				System.out.println(
					index + " position element deleted");
				break;
			}
			else {
				// If current position is not the index
				// continue to next node
				prev = currNode;
				currNode = currNode.next;
				counter++;
			}
		}

		
		if (currNode == null) {
			// Display the message
			System.out.println(
				index + " position element not found");
		}

		// return the List
		return list;
	}

	// **************MAIN METHOD**************

	// method to create a Singly linked list with n nodes
	public static void main(String[] args)
	{
		/* Start with the empty list. */
		LinkedList list = new LinkedList();

		//
		// ******INSERTION******
		//

		// Insert the values
		list = insert(list, 1);
		list = insert(list, 2);
		list = insert(list, 3);
		list = insert(list, 4);
		list = insert(list, 5);
		list = insert(list, 6);
		list = insert(list, 7);
		list = insert(list, 8);

		// Print the LinkedList
		printList(list);

		//
		// ******DELETION AT POSITION******
		//

		// Delete node at position 0
		// In this case the key is ***at head***
		deleteAtPosition(list, 0);

		// Print the LinkedList
		printList(list);

		// Delete node at position 2
		// In this case the key is present ***in the
		// middle***
		deleteAtPosition(list, 2);

		// Print the LinkedList
		printList(list);

		// Delete node at position 10
		// In this case the key is ***not present***
		deleteAtPosition(list, 10);

		// Print the LinkedList
		printList(list);
	}
}
