import Foundation

class Node {
    var prev: Int
    var next: Int
    
    init(prev: Int, next: Int) {
        self.prev = prev
        self.next = next
    }
}

func solution(_ n: Int, _ k: Int, _ cmd: [String]) -> String {
    var table = [Node]()
    for i in 0..<n {
        table.append(Node(prev: i - 1, next: i + 1))
    }
    table[n-1].next = -1
    
    var current = k
    var stack = [Int]()
    var removed = Set<Int>()
    
    for command in cmd {
        let parts = command.split(separator: " ")
        switch parts[0] {
        case "U":
            let x = Int(parts[1])!
            for _ in 0..<x {
                current = table[current].prev
            }
        case "D":
            let x = Int(parts[1])!
            for _ in 0..<x {
                current = table[current].next
            }
        case "C":
            stack.append(current)
            removed.insert(current)
            
            let prev = table[current].prev
            let next = table[current].next
            
            if prev != -1 { table[prev].next = next }
            if next != -1 { table[next].prev = prev }
            
            current = next != -1 ? next : prev
        case "Z":
            let restored = stack.removeLast()
            removed.remove(restored)
            
            let prev = table[restored].prev
            let next = table[restored].next
            
            if prev != -1 { table[prev].next = restored }
            if next != -1 { table[next].prev = restored }
        default:
            break
        }
    }
    
    return (0..<n).map { removed.contains($0) ? "X" : "O" }.joined()
}

