// Esqueleto da classe na qual devem ser implementadas as novas funcionalidades de desenho

public class ImageEx extends Image {

	public ImageEx(int w, int h, int r, int g, int b){

		super(w, h, r, g, b);
	}

	public ImageEx(int w, int h){

		super(w, h);
	}
	
	public void kochCurve(int px, int py, int qx, int qy, int l){

		// Corrige -TODO1: caso o usuario tente passar limiar nao comportado.
		
		if(l <= 1) {
			System.out.println("O limiar para a curva de Koch deve ser maior ou igual a 2.");
			System.exit(1);
		}

		double c = Math.sqrt((qx-px)*(qx-px) + (qy-py)*(qy-py));
		
		if(c < l) {
			drawLine(px, py, qx, qy);
		}
		else {
			double ax = (2*px + qx) / 3;
			double ay = (2*py + qy) / 3;
			double cx = (px + 2*qx) / 3;
			double cy = (py + 2*qy) / 3;
			double mediox = (px + qx) / 2;
			double medioy = (py + qy) / 2;
			double vx = (qx - px);
			double vy = (qy - py);
			double rvx = vy;
			double rvy = -vx;
			double ux = rvx * Math.sqrt(3) / 6;
			double uy = rvy * Math.sqrt(3) / 6;
			double bx = mediox + ux;
			double by = medioy + uy;
			
			kochCurve((int) Math.round(px), (int) Math.round(py), (int) Math.round(ax), (int) Math.round(ay), l);
			kochCurve((int) Math.round(ax), (int) Math.round(ay), (int) Math.round(bx), (int) Math.round(by), l);
			kochCurve((int) Math.round(bx), (int) Math.round(by), (int) Math.round(cx), (int) Math.round(cy), l);
			kochCurve((int) Math.round(cx), (int) Math.round(cy), (int) Math.round(qx), (int) Math.round(qy), l);
		}
	}

	//prepara regionFill(int x, int y, reference_rgb)
	public void regionFill(int x, int y) {
		regionFill(x, y, getPixel(x, y));
	}

	public void regionFill(int x, int y, int reference_rgb){
		if(x < 0 || y < 0 || x >= getWidth() || y >= getHeight()) {return;}
		
		if(getPixel(x, y) == reference_rgb) {
			setPixel(x, y);

			// Corrige -TODO0: caso o usuario utilize REGION_FILL de modo redundante.
			int atual = getPixel(x, y);
			if(atual == reference_rgb) {
				System.out.println("De novo? A região já está preenchido com essa cor, tente outra!");
				System.exit(1);
			}

			regionFill(x+1, y, reference_rgb);
			regionFill(x, y+1, reference_rgb);
			regionFill(x-1, y, reference_rgb);
			regionFill(x, y-1, reference_rgb);
		}
	}

}
