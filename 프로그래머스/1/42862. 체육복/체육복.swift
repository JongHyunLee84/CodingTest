import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var tempLost = lost
    var sortedRe = reserve.sorted(by: <)
    for i in sortedRe {
        if tempLost.contains(i) {
            tempLost.remove(at: tempLost.firstIndex(of: i)!)
        } else if tempLost.contains(i-1) {
            tempLost.remove(at: tempLost.firstIndex(of: i-1)!)
        } else if tempLost.contains(i+1) && !sortedRe.contains(i+1) {
            tempLost.remove(at: tempLost.firstIndex(of: i+1)!)
        }
    }
    return n - tempLost.count
}