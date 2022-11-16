import Foundation

func solution(_ my_string:String) -> [Int] {
    var result: [Int] = []
    for i in my_string {
        if let a: Int = Int(String(i)) {
            result.append(a)
        }
    }
    return result.sorted()
}