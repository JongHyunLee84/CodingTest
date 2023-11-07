import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var progress = progresses
    var speed = speeds
    var ret: [Int] = []
    var index = 0
    while true {
        if index == speed.count { break }
        for i in index..<speed.count {
            progress[i] += speed[i]
        }
        var temp = 0
        for j in index..<speed.count {
            if progress[j] >= 100 {
                index += 1
                temp += 1
            }else {
                break
            }
        }
        if temp != 0 {
            ret.append(temp)
        }
    }
    return ret
}