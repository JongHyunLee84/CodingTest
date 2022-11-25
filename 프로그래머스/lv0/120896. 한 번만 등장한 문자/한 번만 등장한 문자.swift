import Foundation

func solution(_ s:String) -> String {
    var str = s.sorted()
    var result : Set<Character> = []
    var remove : [Character] = []
    for i in str {
        if result.contains(i) {
            remove.append(i)
        }
        result.update(with: i)
    }
    for i in remove {
        result.remove(i)
    }
    
    
    return String(result.sorted())
}