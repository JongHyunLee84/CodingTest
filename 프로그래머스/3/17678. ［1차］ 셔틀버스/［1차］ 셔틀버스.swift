import Foundation

// 시간은 -1하면 99가 아니라 59
func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    // 09:00부터 n회 운행, t분 간격으로 운행, 1회에 m명 태움(시간 안에 도착한 사람들만)
    // 콘은 같은 시간에 도착하면 가장 뒤에 서게됨.
    // 콘이 가장 늦게 탈 수 있는 시간을 구한다.
    var result = ""
    var arr = mutate(timetable)
    var idx = 0
    var count = timetable.count
    // timetable을 소팅 (그냥 Int로 변환 후 소팅 해도됨)
    // print(Int(arr.remove(at: 2).joined(separator: "")))
    var sorted = arr.sorted(by: <)
    var start = 540
    var turn = 0
    while(idx < count) {
        var temp = 0 // 버스에 탄 인원
        if turn == n-1 {
            // 마지막 운행일 경우 콘이 탄다.
            // 콘이 마지막 m번째에 걸릴 수 있는 시간대를 구한다. (만약 버스가 꽉 찬다면 -> m번째 타는 사람보다 1분 빠르게, 없다면 해당 운행 출발 시간에 콘이 도착)
            while(idx < count && temp != m) {
                if sorted[idx] <= start {
                    temp += 1
                    idx += 1
                } else {
                    break
                }
            }
            if temp >= m {
                return toTime(sorted[idx-1] - 1)// 1마지막 놈보다 1분 빠르게
            } else {
                return toTime(start)
            }
        } else {
            // 매번 시간 안에 온 사람들을 m명 태우고 출발 (현재시간 + t)(sorted에서 탄 사람들 빼기)
            // 컷트된 사람들은 다음 운행에 다시 순서대로 탄다.
            for j in idx..<count {
                if sorted[j] <= start && temp < m {
                    idx += 1
                    temp += 1
                } else {
                    break
                }
            }
            start += t
            turn += 1
        }
    }
    
    return result
}

func mutate(_ arr: [String]) -> [Int] {
    return arr.map {
        var temp = Array($0)
        let hour = Int(String(temp[0]) + String(temp[1]))!
        let minute = Int(String(temp[3]) + String(temp[4]))!
        let total = (hour * 60) + minute
        
        return total
    }
}

func toTime(_ num: Int) -> String {
    var hour = String(num / 60)
    var minute = String(num % 60)
    if hour.count != 2 {
        hour = "0" + hour
    }
    if minute.count != 2 {
        minute = "0" + minute
    }
    var arr = Array(hour + ":" + minute)
    return String(arr)
}
