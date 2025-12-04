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

    var nums = line.map { it.toString().toInt() }.toMutableList()
    var max = ""
    var digitsNeeded = 12
    while (digitsNeeded != 0) {
        val maxDigit = nums.slice(0..nums.size - digitsNeeded).max()
        val index = nums.indexOf(maxDigit)
        nums = nums.slice(index + 1 until nums.size).toMutableList()
        max += maxDigit
        digitsNeeded--
    }

    total += max.toLong()
}
println(total)