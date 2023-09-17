document.querySelector(".cross").style.display = "none";
document.querySelector(".ham").addEventListener("click", () => {
  document.querySelector(".sidebar").classList.toggle("sidebarGo");

  setTimeout(() => {
    document.querySelector(".ham").style.display = "none";
  }, 100);
  setTimeout(() => {
    document.querySelector(".cross").style.display = "inline";
  }, 300);
});

document.querySelector(".cross").addEventListener("click", () => {
  document.querySelector(".sidebar").classList.toggle("sidebarGo");
  setTimeout(() => {
    document.querySelector(".ham").style.display = "inline";
    document.querySelector(".cross").style.display = "none";
  }, 100);
});
