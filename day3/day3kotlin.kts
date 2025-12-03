import java.io.File

val file = File("./day3input.txt")
val content = file.readLines()

var total : Long = 0
//for (line in content) {
//    var index = 0
//    var max = 0
//    val nums = line.map { it.toString().toInt() }
//    val maxNum = nums.max()
//    println(maxNum)
//    index = nums.indexOf(maxNum)
//    if (index != nums.size - 1) {
//       val secondMax = nums.slice(index + 1..<nums.size).max()
//        println(maxNum.toString() + secondMax.toString())
//        total += (maxNum.toString() + secondMax.toString()).toInt()
//    } else {
//        val secondMax = nums.slice(0..<index).max()
//        println(maxNum.toString() + secondMax.toString())
//        total +=(secondMax.toString() + maxNum.toString()).toInt()
//    }
//}
for (line in content) {

    val nums = line.map { it.toString().toInt() }.toMutableList()
    val arr = Array<Int>(nums.size) {0}.toMutableList()

    repeat(12) {

        val maxDigit = nums.max()
        val index = nums.indexOf(maxDigit)
        arr[index] = maxDigit
        nums[index] = 0
    }
    val new_arr = arr.filter { it != 0 }


    println(new_arr.joinToString("").toLong())
    total +=new_arr.joinToString("").toLong()
}
println(total)