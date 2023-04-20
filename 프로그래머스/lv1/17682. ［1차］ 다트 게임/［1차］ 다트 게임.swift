func solution(_ dartResult:String) -> Int {
    // 형식 - 점수|보너스|[옵션?]
    // 보너스 - S 1제곱, D 2제곱, T 3제곱
    // 옵션 - * 앞 점수(앞이 없을 시 해당 점수만), 해당 점수 각각 2배 , # 해당 점수 마이너스
    
    // 숫자를 기준으로 [str] 나누고
    var array: [String] = []
    var add = ""
    for i in dartResult {
        if i.isNumber && add != "1" {
            array.append(add)
            add = ""
            add += String(i)
        } else {
            add += String(i)
        }
    }
    array.append(add)

    // 요소들 마다 뒤 보너스, 옵션 구분해서 result: [str]에 넣어주기 -> return sum
    var result: [Int] = []
    for i in array {
        var a = 0
        var num = ""
        var bonus = ""
        var option = ""
        for j in i {
            let z = String(j)
            if j.isNumber {
                num += z
            } else if j == "S" || j == "D" || j == "T" {
                bonus = z
            } else if j == "*" || j == "#" {
                option = z
            }
        }
        switch bonus {
        case "S":
            a = Int(num)!
        case "D":
            a = Int(num)! * Int(num)!
        case "T":
            a = Int(num)! * Int(num)! * Int(num)!
        default:
            break
        }
        switch option {
        case "*":
            a = a * 2
            if result.count != 0 {
                result[result.count-1] = result.last! * 2
            }
        case "#":
            a = a * -1
        default:
            break
        }
        result.append(a)
    }
    return result.reduce(0, +)
}