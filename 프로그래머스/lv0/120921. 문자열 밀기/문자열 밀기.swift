import Foundation

func solution(_ A:String, _ B:String) -> Int {
    var str = Array(A)
    var removed = ""
    var count = 0
    for _ in 0..<A.count {
        if String(str) == B {
            return count
        }
        removed = String(str.removeLast())
        str.insert(contentsOf: removed, at: 0)
        count += 1
                
    }
        return -1
    }
    
