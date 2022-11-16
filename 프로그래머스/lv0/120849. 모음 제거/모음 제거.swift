import Foundation

func solution(_ my_string:String) -> String {
    var array: [Character] = ["a", "e", "i", "o", "u"]
    return my_string.filter { !array.contains($0) }
}
