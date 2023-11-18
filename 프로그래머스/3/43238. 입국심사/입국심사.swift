import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var left: Int64 = Int64(times.min()!)
    var right: Int64 = Int64(times.max()! * n)
    var mid: Int64 = 0
    var minTime = right
    while(left <= right) {
        mid = (left+right)/2
        // print(mid)
        var temp = 0
        for i in times {
            temp += Int(mid) / i
            
        if temp >= n {
            right = mid - 1
            minTime = mid
            break
        }
        }
        // temp = mid동안 심사 받은 사람의 수
         if temp < n {
            left = mid + 1
        }
    }
    return minTime
}