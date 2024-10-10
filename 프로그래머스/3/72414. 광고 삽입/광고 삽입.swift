import Foundation

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {
    // 모든 시간을 초단위로 변경
    // 0초부터 play_time의 마지막 초까지 배열로 만들어줌
    // logs를 돌며 초단위로 시작시간에 +1, 종료시간에 -1을 넣어줌
    // adv_time을 0초부터 슬라이딩 윈도우하며 어느 범위에서 max가 나오는지 기록, max는 클 경우에만, 크거나 같은 경우 x
    let totalPlay = toSecond(play_time)
    var array = Array(repeating: 0, count: totalPlay+2)
    for i in logs {
        let tempArr = i.split(separator: "-")
        let start = toSecond(String(tempArr[0]))
        let end = toSecond(String(tempArr[1]))
        array[start] += 1
        array[end] -= 1
    }
    var sum = Array(repeating: 0, count: totalPlay+2)
    var temp = 0
    for i in 0...totalPlay {
        temp += array[i]
        sum[i] = temp
    }
    var advTime = toSecond(adv_time)
    var result = 0
    var maxStart = 0
    var start = 1
    var end = advTime
    var current = 0
    for i in 0...advTime {
        current += sum[i]
    }
    result = current
    while end < totalPlay {
        end += 1
        current += sum[end]
        current -= sum[start]
        start += 1
        if result < current {
            result = current
            maxStart = start
        }
    }
    return toTime(maxStart)
}

func toSecond(_ value: String) -> Int {
    let array = value.split(separator: ":").map { Int($0)! }
    let hours = array[0]
    let minutes = array[1]
    let seconds = array[2]
    var result = 0 
    result += hours * 3600
    result += minutes * 60
    result += seconds
    return result
}

func toTime(_ value: Int) -> String {
    var temp = value
    var result: [Int] = []
    result.append(temp / 3600)
    temp %= 3600
    result.append(temp / 60)
    temp %= 60
    result.append(temp)
    var strTemp = result.map { isOverTen($0) ? String($0) : ("0" + String($0)) }
    return strTemp.joined(separator: ":")
}

func isOverTen(_ value: Int) -> Bool {
    value >= 10
}