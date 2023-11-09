import Foundation

func solution(_ jobs:[[Int]]) -> Int {
    var jobsTemp = jobs
    var time = 0
    var ret = 0
    var endCount = 0
    while endCount != jobs.count {
        let optimalRequestList = jobsTemp.filter { $0[0] <= time }.sorted { $0[1] < $1[1] }
        if optimalRequestList.count > 0 {
        var optimalRequest = optimalRequestList[0]
        time += optimalRequest[1]
        ret += time - optimalRequest[0]
        endCount += 1
        jobsTemp = jobsTemp.filter { $0 != optimalRequest }
        } else {
            time += 1
        }
    }
    return ret / endCount // 소수점은 버린다.
}