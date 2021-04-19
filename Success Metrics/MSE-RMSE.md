# MAE and RMSE
Mean Absolute Error (MAE) and Root Mean Squared Error (RMSE) are two similar metrics commonly used to measure accuracy for continuous variables.



## The Definitions

- **MAE** measures the average magnitude of the errors in a set of predictions, without taking their direction into consideration. How it works is that it takes an absolute difference of actual observation and a prediction where all individual differences have the same weight.

  

  ![MAE](https://i.imgur.com/C3E7ANi.png)

  

- **RMSE** is the standard deviation of the prediction errors which are a measure of how far from the regression line data points are. RMSE tells us how concentrated the data is around the line of the best fit. As MAE, it also measures the magnitude of an error.

  

  ![RMSE](https://i.imgur.com/098ti5G.png)

  


## Similarities and Differences

Both of these formulas express the average model prediction error in units of the variable of interest. Both of them range from 0 to ∞ and do not care about the direction of errors. They are negatively-oriented scores, which means lower values are considered better.

The way they are different is in how they approach errors. RMSE, since the errors are squared before they are averaged, _a greater weight is assigned to large errors. This implication suggests that we want to use it in cases where they are particularly undesirable._

One thing to keep in mind that **RMSE does not necessarily increase with the variance of the errors. RMSE increases with the variance of the frequency distribution of error magnitudes.**



![Examples](https://i.imgur.com/2E2Jf8C.png)

![Examples](https://i.imgur.com/eRVMfwP.png)

