import Foundation

func solution(_ my_string:String, _ letter:String) -> String {
    var stringArray = Array(my_string)
    var result: [Character] = []
    for i in stringArray {
        if i == Character(letter) {
            continue
        } else {
            result.append(i)
        }
    }
    return String(result)
}