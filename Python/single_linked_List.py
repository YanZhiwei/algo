class Node(object):
    def __init__(self, data: int) -> None:
        self.data = data
        self.next: Node | None = None


class SingleLinkedList(object):
    def __init__(self) -> None:
        self.__l = None

    def headerInsert(self, data: int):
        node = Node(data)
        node.next = self.__l.next
        self.__l.next = node
        self.__l.data = self.__l.data + 1

    def tailInsert(self, data: int):
        lastNode = self.__l
        for i in range(self.__l.data):
            lastNode = lastNode.next
        node = Node(data)
        node.next = None
        lastNode.next = node
        self.__l.data = self.__l.data + 1

    def delete(self, data: int) -> bool:
        preNode = self.__l
        node = self.__l.next
        while node:
            if node.data == data:
                self.__l.data = self.__l.data - 1
                preNode.next = node.next
                return True
            else:
                preNode = node
                node = node.next
        return False

    def printList(self):
        node = self.__l.next
        while node:
            print(f"node={node.data}")
            node = node.next

    def initList(self):
        self.__l = Node(0)


if __name__ == "__main__":
    linkedList = SingleLinkedList()
    linkedList.initList()
    linkedList.headerInsert(1)
    linkedList.headerInsert(2)
    linkedList.headerInsert(3)
    linkedList.headerInsert(4)
    linkedList.headerInsert(5)
    linkedList.tailInsert(6)
    linkedList.printList()
    if linkedList.delete(3):
        print("success delete")
    else:
        print("fail delete")
    linkedList.printList()
