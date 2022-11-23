import Foundation


func solution(_ before:String, _ after:String) -> Int {

    var afArray = Array(after)
    for i in before {
        if afArray.contains(i) {
            afArray.remove(at: afArray.firstIndex(of: i)!)
        }
    }
    

    return afArray.isEmpty ? 1 : 0
}
