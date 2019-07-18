function toggleSpecialNav() {
	var x = document.getElementById("specialNav");
	var y = document.getElementById("wrapper0");
	if (x.style.display === "block") {
		x.style.display = "none";
		y.style.display = "block";

	} else {
		x.style.display = "block";
		y.style.display = "none";
	}
}