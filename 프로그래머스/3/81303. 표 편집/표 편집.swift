import Foundation

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var list = DoubleLinkedList<Int>()
    for i in 0..<n {
        list.insertLast(i)
    }
    
    var current = list[k]
    var deleted: [DoubleNode<Int>?] = []
    
    for i in 0..<cmd.count {
        let str = cmd[i]
        if str.contains("U") {
            let num = Int(str.split(separator: " ")[1])!
            for _ in 0..<num {
                current = current?.prev
            }
        } else if str.contains("D") {
            let num = Int(str.split(separator: " ")[1])!
            for _ in 0..<num {
                current = current?.next
            }
        } else if str.contains("C") {
            deleted.append(current)
            let nextNode = current?.next
            let prevNode = current?.prev
            
            nextNode?.prev = prevNode
            prevNode?.next = nextNode
            
            if current === list.tail {
                current = prevNode
                list.tail = prevNode
            } else {
                current = nextNode
            }
            
            if current === nil {
                current = list.tail
            }
        } else { // Z command
            let node = deleted.removeLast()
            let nextNode = node?.next
            let prevNode = node?.prev
            
            nextNode?.prev = node
            prevNode?.next = node
            
            if nextNode == nil {
                list.tail = node
            }
        }
    }
    
    var result = Array(repeating: "O", count: n)
    for node in deleted {
        if let index = node?.value {
            result[index] = "X"
        }
    }
    
    return result.joined()
}

public class DoubleNode<T> {
    public var next: DoubleNode?
    public weak var prev: DoubleNode? // 이전 노드와 다음 노드 간 서로의 ref count를 올리기에 레퍼런스 사이클 발생
    public var value: T
    
    public init(
        next: DoubleNode? = nil,
        prev: DoubleNode? = nil,
        value: T
    ) {
        self.next = next
        self.prev = prev
        self.value = value
    }
}

public class DoubleLinkedList<T> {
    public var head: DoubleNode<T>?
    public var tail: DoubleNode<T>?
    
    public init(
        head: DoubleNode<T>? = nil,
        tail: DoubleNode<T>? = nil
    ) {
        self.head = head
        self.tail = tail
    }
    
    public subscript(index: Int) -> DoubleNode<T>? {
        var currentNode = head
        var idx = 0
        while currentNode != nil {
            if idx == index {
                return currentNode
            }
            currentNode = currentNode?.next
            idx += 1
        }
        return nil
    }
    
    public func insertLast(_ value: T) {
        let newNode = DoubleNode(value: value)
        if tail == nil { // head로 비교해도됨
            self.head = newNode
            self.tail = newNode
        } else {
            newNode.prev = tail
            tail?.next = newNode
            tail = newNode
        }
    }
}