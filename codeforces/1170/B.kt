// kartikay26

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
	var n = readInt()
	var a = readInts()
	var c = 0;
	var m1 = 0
	var m2 = 0
	for (i in 0..(n-1)){
		if (a[i] >= m2) {
			m1 = m2
			m2 = a[i]
		} else if (a[i] >= m1) {
			m1 = a[i]
		} else {
			// a[i] smaller than both
			c++
		}
		// println("$m1 $m2 ${a[i]}, $c")
	}
	println("$c")
}
