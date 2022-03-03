package leetcode;

//https://leetcode.com/problems/design-circular-queue/submissions/

public class DesignCircularQueue {
    public static void main(String[] args) {
        test1();
    }

    private static void test() {
        MyCircularQueue obj = new MyCircularQueue(5);
        boolean param_1 = obj.enQueue(10);
        boolean param_2 = obj.deQueue();
        int param_3 = obj.Front();
        int param_4 = obj.Rear();
        boolean param_5 = obj.isEmpty();
        boolean param_6 = obj.isFull();

        System.out.println(param_1);
        System.out.println(param_2);
        System.out.println(param_3);
        System.out.println(param_4);
        System.out.println(param_5);
        System.out.println(param_6);
    }

    private static void test1() {
        MyCircularQueue myCircularQueue = new MyCircularQueue(3);
        System.out.println(myCircularQueue.enQueue(1)); // return True
        System.out.println(myCircularQueue.enQueue(2)); // return True
        System.out.println(myCircularQueue.enQueue(3)); // return True
        System.out.println(myCircularQueue.enQueue(4)); // return False
        System.out.println(myCircularQueue.Rear());           // return 3
        System.out.println(myCircularQueue.isFull());   // return True
        System.out.println(myCircularQueue.deQueue());  // return True
        System.out.println(myCircularQueue.enQueue(4)); // return True
        System.out.println(myCircularQueue.Rear());     // return 4
    }

    static class MyCircularQueue {
        int[] list;
        int rear;
        int front;
        int dataSize;

        public MyCircularQueue(int k) {
            this.list = new int[k];
            this.rear = -1;
            this.front = 0;
            this.dataSize = 0;
        }

        public boolean enQueue(int value) {
            if(dataSize < list.length) {
                rear = ++rear % list.length;
                list[rear] = value;
                dataSize++;
                return true;
            }

            return false;
        }

        public boolean deQueue() {
            if(dataSize > 0) {
                front = ++front % list.length;
                dataSize--;
                return true;
            }

            return false;
        }

        public int Front() {
            return dataSize > 0 ? list[front] : -1;
        }

        public int Rear() {
            return dataSize > 0 ? list[rear] : -1;
        }

        public boolean isEmpty() {
            return dataSize == 0;
        }

        public boolean isFull() {
            return dataSize == list.length;
        }
    }
}
