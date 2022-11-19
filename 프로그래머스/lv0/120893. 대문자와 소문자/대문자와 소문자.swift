import Foundation

func solution(_ my_string:String) -> String {
    var array = Array(my_string)
    var upper = Array(my_string.uppercased())
    var lower = Array(my_string.lowercased())
    var result: [Character] = []
    var index = 0
    for i in array {
        if i != upper[index] {
            result.append(contentsOf: i.uppercased())
        } else if i != lower[index] {
            result.append(contentsOf: i.lowercased())
        }
        index += 1
    }
    return String(result)
}