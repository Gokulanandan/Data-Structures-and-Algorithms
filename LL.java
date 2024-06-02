package Sorting_Algorithms;

public class LL {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        /*list.insertNodeSorted(30);
        list.insertNodeSorted(20);
        list.insertNodeSorted(80);
        list.insertNodeSorted(10);
        list.insertNode(40);
        list.printList();
        list.printTail();
        list.reverseList();
        list.printList();
        list.printTail();
        list.insertNode(35);
        list.insertNode(45);
        list.printList();
        list.deleteNode(80);
        list.printList();
        list.MS();*/
        list.insertNode(40);
        list.insertRecurse(20,40,0);
        list.insertRecurse(15,40,0);
        list.printList();
    }
}
class LinkedList {
    private int size;
    private Node head;
    private Node tail;

    LinkedList(){
        this.size=0;
    }
    public void insertNode(int val){
        if(head == null) {
            head = tail = new Node(val);
            return;
        }
        tail.next = new Node(val);
        tail = tail.next;
    }

    public void insertRecurse(int val,int index,int b){
        head = insertRecursive(head, val, index, b)   ;
    }
    public Node insertRecursive(Node head, int val, int index, int b){
        if(head == null ) {
            System.out.println("Either Linked list is Empty of index not found");
            return head;
        }
        Node tmp = head;
        if(index == tmp.val) {
            if (b == 0) { //Add After index
               Node node = new Node(val);
               node.next = tmp.next;
               tmp.next = node;
               if(tmp == tail) {
                   tail = node;
               }
               return tmp;
            } else { // Add before index
                Node node = new Node(val);
                node.next = tmp;
                if(tmp == head){
                    head = node;
                    return head;
                }
                return node;
            }
        }
        tmp.next = insertRecursive(tmp.next, val, index, b);
        return head;
    }

    public Node partition(Node head){
        if (head == null || head.next == null){
            return head;
        }
        Node slow = head;
        Node fast = head.next;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public Node mergeList(Node a, Node b){
        if(a == null){
            return b;
        }
        if(b == null) {
            return a;
        }

        Node list = null;
        if(a.val > b.val){
            list = b;
            list.next = mergeList(a,b.next);
        } else {
            list = a;
            list.next = mergeList(a.next,b);
        }
        return list;
    }

    public Node mergeSort(Node head){
        if(head == null || head.next == null) {
            return head;
        }
        //partition
        Node a = null;
        Node b = null;
        Node middle = partition(head);
        a = head;
        if(middle != null) {
            b = middle.next;
        }
        middle.next = null;
        //mersort a
        a = mergeSort(a);
        //mergesort b
        b = mergeSort(b);
        //merge list
        return mergeList(a,b);

    }

    public void MS(){
        head = mergeSort(head);
    }
    public void reverseList() {
           head = reverse(head);
        }
        public Node reverse(Node head){

            if (head == null || head.next == null) {
                return head;
            }

        /* reverse the rest list and put
        the first element at the end */
            Node rest = reverse(head.next);
            head.next.next = head;

            /* tricky step -- see the diagram */
            head.next = null;

            /* fix the head pointer */
            tail = head;
            return rest;
    }

    public void insertNodeSorted(int val){
        if(head == null) {
            head = tail = new Node(val);
            return;
        }
        Node curr = head;
        Node prev = head;
        Node node = new Node(val);
        while( curr != null) {
            if (curr.val < node.val) {
                prev = curr;
                curr = curr.next;
            } else {
                node.next = curr;
                if(curr == prev) {
                    head = node;
                } else {
                    prev.next = node;

                }
                return;
            }
        }
        tail.next = node;
        tail = node;
    }

    public void printList(){
        Node tmp = head;
        while(tmp!=null){
            System.out.print("|"+tmp.val+"|->");
            tmp = tmp.next;
        }
        System.out.println("|NULL|");
    }

    public void printTail(){
        Node tmp = tail;
        while(tmp != null){
            System.out.println("Tail data is " + tail.val);
            tmp = tmp.next;
        }
    }
    public void deleteNode(int val){
        Node tmp = head;
        Node prev = head;
        while(tmp!=null){
            if(tmp.val == val) {
                prev.next = tmp.next;
                tmp.next = null;
                return;
            } else {
                prev = tmp;
                tmp = tmp.next;
            }
        }
        System.out.println("Val" +val+ "is not found in the Linked List");
    }

    class Node {
        int val;
        Node next;

        Node(int val){
            this.val = val;
            this.next = null;
        }
    }
}
