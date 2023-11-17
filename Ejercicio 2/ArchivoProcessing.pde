import processing.serial.*;

Serial puerto;
int estadoE1, estadoE2;
boolean estadoL1, estadoL2;

void setup() {
  size(400, 200);
  
  puerto = new Serial(this, "COM6", 9600);
  
  estadoE1 = estadoE2 = 0;
  estadoL1 = estadoL2 = false;
}

void draw() {
  background(255);
  
  fill(200);
  rect(50, 20, 100, 40);
  fill(0);
  text("Entradas", 90, 45);
  
  fill(200);
  rect(200, 20, 40, 40);
  fill(0);
  text("E1", 220, 45);
  
  fill(200);
  rect(260, 20, 40, 40);
  fill(0);
  text("E2", 280, 45); 
  
  fill(200);
  rect(50, 120, 100, 40);
  fill(0);
  text("Salidas", 90, 145);
  
  fill(estadoL1 ? color(0, 255, 0) : color(255, 0, 0));
  ellipse(200, 140, 30, 30);
  fill(0);
  text("L1", 200, 145);
  
  fill(estadoL2 ? color(0, 255, 0) : color(255, 0, 0));
  ellipse(260, 140, 30, 30);
  fill(0);
  text("L2", 260, 145);
}

void mousePressed() {
  if (mouseX > 200 && mouseX < 240 && mouseY > 20 && mouseY < 60) {
    estadoL1 = !estadoL1;
    enviarDatosArduino();
  }
  
  if (mouseX > 260 && mouseX < 300 && mouseY > 20 && mouseY < 60) {
    estadoL2 = !estadoL2;
    enviarDatosArduino();
  }
}

void enviarDatosArduino() {
  puerto.write("L1:" + (estadoL1 ? "1" : "0") + ";L2:" + (estadoL2 ? "1" : "0") + ";");
}
