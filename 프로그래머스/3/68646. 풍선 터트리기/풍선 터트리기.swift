import Foundation

func solution(_ a:[Int]) -> Int {
    var ll = Array(repeating: 0, count: a.count)
    var rr = Array(repeating: 0, count: a.count)
    var temp = Int.max
    var idx = 0
    while(a.count != idx) {
        if a[idx] < temp {
            ll[idx] = a[idx]
            temp = a[idx]
        } else {
            ll[idx] = temp
        }
        idx += 1
    }
    idx -= 1
    temp = Int.max
    while(idx >= 0) {
        if a[idx] < temp {
            rr[idx] = a[idx]
            temp = a[idx]
        } else {
            rr[idx] = temp
        }
        idx -= 1
    }
    var result = 0
    for i in 0..<a.count {
        if ll[i] >= a[i] || rr[i] >= a[i] {
            result += 1
        }
    }
    return result
}