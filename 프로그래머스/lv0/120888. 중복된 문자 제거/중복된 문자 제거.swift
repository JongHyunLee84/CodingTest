import Foundation

func solution(_ my_string:String) -> String {
    var array : [Character] = []
    
    for i in my_string {
        if !array.contains(i) {
            array.append(i)
        }
    }
    return String(array)
}