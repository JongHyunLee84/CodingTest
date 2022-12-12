import Foundation

func solution(_ s:String) -> Bool
{
    var p = 0
    var y = 0
    for i in s.lowercased() {
        if i == "p" {
            p += 1
        } else if i == "y" {
            y += 1
        }
    }
    return p == y ? true : false
}