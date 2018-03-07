package com.google.jnirefdemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.TextView;

import java.util.Stack;

public class MainActivity extends Activity {
    private Stack<Long> birds = new Stack<>();
    private Stack<Long> flowers = new Stack<>();
    private Stack<Long> candies = new Stack<>();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void newRef(View view) {
        if (((RadioButton)findViewById(R.id.rbFlower)).isChecked()) {
            Object o = new Flower();
            long ref = Interop.NewRef(o);
            flowers.push(ref);
        }

        if (((RadioButton)findViewById(R.id.rbBird)).isChecked()) {
            Object o = new Bird();
            long ref = Interop.NewRef(o);
            birds.push(ref);
        }

        if (((RadioButton)findViewById(R.id.rbCandy)).isChecked()) {
            Object o = new Candy();
            long ref = Interop.NewRef(o);
            candies.push(ref);
        }
        selectNiceThing(view);
    }

    public void deleteRef(View view) {
        if (((RadioButton)findViewById(R.id.rbFlower)).isChecked()) {
            if (!flowers.isEmpty()) {
                Interop.ReleaseRef(flowers.pop());
            }
        }

        if (((RadioButton)findViewById(R.id.rbBird)).isChecked()) {
            if (!birds.isEmpty()) {
                Interop.ReleaseRef(birds.pop());
            }
        }

        if (((RadioButton)findViewById(R.id.rbCandy)).isChecked()) {
            if (!candies.isEmpty()) {
                Interop.ReleaseRef(candies.pop());
            }
        }
        selectNiceThing(view);
    }

    public void selectNiceThing(View view) {
        TextView counterView = (TextView)findViewById(R.id.tvCount);
        if (((RadioButton)findViewById(R.id.rbFlower)).isChecked()) {
            counterView.setText(String.valueOf(flowers.size()));
        }

        if (((RadioButton)findViewById(R.id.rbBird)).isChecked()) {
            counterView.setText(String.valueOf(birds.size()));
        }

        if (((RadioButton)findViewById(R.id.rbCandy)).isChecked()) {
            counterView.setText(String.valueOf(candies.size()));
        }
    }

}
