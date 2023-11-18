import Foundation

func solution(_ name:String) -> Int {
    //"ABBAAB"
    // 연속적으로 A가 아닌 놈이 더 적은 놈한테 간다
    // 완탐?
    // if A가 아닌 놈이 없으면 끝낸다.
    // 좌를 살펴서 A가 아닌 놈이 있으면 간다.
    // 우를 살펴서 A가 아닌 놈이 있으면 간다. 
    var ret: Int = .max
    var cnt = 0
    var array = name.map { $0 }
    if name.first! != "A" {
        let ascii = Int(name.first!.asciiValue!)-65
        cnt += min(ascii, abs(ascii-26))
        array[0] = "A"
    }
    func go(_ temp: [Character],_ idx: Int,_ cnt: Int) {
        // print(temp)
        if temp.filter { $0 != "A" }.count == 0 {
            ret = min(ret, cnt)
            return 
        }
        var tempIdx = 0
        var indexArray: [Int] = []
        for i in 1..<(name.count) {
            let tempNum = (idx+i)%name.count
            indexArray.append(tempNum)
        }
        for i in indexArray {
            tempIdx += 1
            if temp[i] != "A"{
                // A를 만들고 break
                let ascii = Int(temp[i].asciiValue!)-65
                var tempCnt = cnt + min(ascii, abs(ascii-26))
                var temp1 = temp; temp1[i] = "A"
                go(temp1, i, tempCnt+tempIdx)
                break
            }
        }
        tempIdx = 0
        for i in indexArray.reversed() {
            tempIdx += 1
            if temp[i] != "A"{
                // A를 만들고 break
                let ascii = Int(temp[i].asciiValue!)-65
                var tempCnt = cnt + min(ascii, abs(ascii-26))
                var temp1 = temp; temp1[i] = "A"
                go(temp1, i, tempCnt+tempIdx)
                break
            }
        }
    }
    go(array, 0, cnt)
    
    return ret
}