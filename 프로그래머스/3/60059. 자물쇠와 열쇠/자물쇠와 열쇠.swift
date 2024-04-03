import Foundation

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    var arrCount = lock.count + (key.count * 2 - 2)
    var lockCount = lock.count
    var keyCount = key.count
    var tempKey = key
    var startIdx = (key.count * 2 - 2) / 2
    var endIdx = startIdx + lockCount - 1
    var locks: [Dot] = []
    var keys: [[Dot]] = []
    var result = false
    for z in 0..<4 {
        var tempKeys: [Dot] = []
        for i in 0..<keyCount {
            for j in 0..<keyCount {
                if tempKey[i][j] == 1 {
                    tempKeys.append(.init(i,j))
                }
            }
        }
        keys.append(tempKeys)
        rotate(&tempKey)
    }
    for i in 0..<lock.count {
        for j in 0..<lock.count {
            if lock[i][j] == 0 {
                locks.append(.init(i,j))
            }
        }
    }
    var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: arrCount), count: arrCount)
    // y, x가 0,0일 때부터 arr 배열에 y값, x값을 시작점으로 key를 할당(key 1인 좌표 배열 갖고 있으면서 y,x 값에 맞게 1인 애들만 할당하면됨.)
    // 처음 체크, 90도 3번 돌려주면서 체크 true나오면 종료
    // true 아니라면 x값을 오른쪽으로 간다, 다 갔으면 다시 x가 0부터 y는 +1
    // 마지막 key 채우는 index까지 모두 반복했는데 없으면 false
    func check(_ arr: [[Int]]) -> Bool {
        var count = 0
        for i in startIdx...endIdx {
            for j in startIdx...endIdx {
                if arr[i][j] == 1 {
                    if !locks.contains(.init(i-startIdx,j-startIdx)) {
                        return false
                    } else {
                        count += 1
                    }
                }
            }
        }
        return count == locks.count
    }
    func go(_ y: Int, _ x: Int) {
        if y == arrCount - keyCount && x == arrCount - keyCount {
            return
        }
        // tempArr에 key할당
        for i in keys {
            var tempArr = arr
            for j in i {
                tempArr[j.y + y][j.x + x] = 1
            }
//            for ii in startIdx...endIdx {
//                for jj in startIdx...endIdx {
//                    print(tempArr[ii][jj], terminator: "")
//                }
//                print("")
//            }
//            print("")
            if check(tempArr) {
//                print(y,x)
//                for i in 0..<tempArr.count {
//                    for j in 0..<tempArr.count {
//                        print(tempArr[i][j], terminator: "")
//                    }
//                    print("")
//                }
//                print("")
                result = true
                return
            }
        }
        if x < arrCount - keyCount {
            go(y, x+1)
        } else {
            go(y+1, 0)
        }
    }
    go(0, 0)
    return result
}

func rotate(_ arr: inout [[Int]]) {
    var result: [[Int]] = []
    for i in (0..<arr.count) {
        var tempArr: [Int] = []
        for j in (0..<arr.count).reversed() {
            tempArr.append(arr[j][i])
        }
        result.append(tempArr)
    }
    arr = result
}

struct Dot: Equatable {
    var y, x: Int
    init(_ y: Int, _ x: Int) {
        self.y = y
        self.x = x
    }
}