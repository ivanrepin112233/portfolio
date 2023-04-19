/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package my.numberaddition;

import java.io.Serializable;
import my.numberaddition.Result;

interface Operationable{
    void execute();
}
/**
 *
 * @author maksv
 */
public class RecIntegral extends Thread implements Serializable {

    private float bottomBorder;
    private float upperBorder;
    private float step;
    private Result<Float> result = new Result();

    public RecIntegral(float bottomBorder, float upperBorder, float step) throws InException {
         if(bottomBorder < 0.000001 || bottomBorder > 1000000 || upperBorder < 0.000001 || upperBorder > 1000000 || bottomBorder > upperBorder){
            throw new InException();
        }
        
        this.bottomBorder = bottomBorder;
        this.upperBorder = upperBorder;
        this.step = step;
    }

    public void run() {
        CalculateResult();
    }
    
    public void CalculateResult() {
        if ((this.bottomBorder > this.upperBorder) || (this.bottomBorder == 0) || (this.upperBorder == 0) || (this.step == 0)) {
            return;
        }
        
        if ((this.bottomBorder < 0) && (this.upperBorder > 0)) {
            this.result.str = "Infinite";
        } else {
            float next_step = this.bottomBorder;
            float prev_step = this.bottomBorder;
            float result = 0;

            do {
                next_step = next_step + this.step;
                if (next_step > this.upperBorder) {
                    next_step = this.upperBorder;
                }
                float iteration_result = 1 / next_step + 1 / prev_step;
                iteration_result = iteration_result * (next_step - prev_step) / 2;
                result += iteration_result;
                prev_step = next_step;
            } while (next_step != this.upperBorder);

            this.result.obj = result;
        }
    }

    public float GetBottomBorder() {
        return this.bottomBorder;
    }

    public float GetUpperBorder() {
        return this.upperBorder;
    }

    public float GetStep() {
        return this.step;
    }

    public Result<Float> GetResult() {
        return this.result;
    }

}
