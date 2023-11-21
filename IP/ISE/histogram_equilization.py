import numpy as np
import matplotlib.pyplot as plt

# Function to perform histogram equalization
def histogram_equalization(image_path):
    # Load the image
    img = plt.imread(image_path)

    # Convert the image to grayscale if it's in color
    if len(img.shape) == 3:
        img = np.mean(img, axis=2)

    # Calculate the histogram of the original image
    original_hist, bins = np.histogram(img.flatten(), bins=256, range=(0, 256))

    # Calculate the cumulative distribution function (CDF)
    cdf = original_hist.cumsum()

    # Normalize the CDF to be in the range [0, 255]
    cdf_normalized = ((cdf - cdf.min()) * 255) / (cdf.max() - cdf.min())

    # Map the values in the original image to their corresponding values in the equalized image
    equalized_img = cdf_normalized[img.astype(int)]

    # Convert the equalized matrix back to an image
    equalized_img = equalized_img.astype(np.uint8)

    # Calculate the histogram of the equalized image
    equalized_hist, _ = np.histogram(equalized_img.flatten(), bins=256, range=(0, 256))

    # Calculate the cumulative distribution function (CDF)
    equalized_cdf = equalized_hist.cumsum()

    # Normalize the CDF to be in the range [0, 255]
    equalized_cdf_normalized = ((equalized_cdf - equalized_cdf.min()) * 255) / (equalized_cdf.max() - equalized_cdf.min())

    # Plot the original image and its histogram
    plt.figure(figsize=(12, 6))
    plt.subplot(2, 3, 1)
    plt.imshow(img, cmap='gray')
    plt.title('Original Image')
    plt.axis('off')

    plt.subplot(2, 3, 2)
    plt.plot(original_hist, color='b')
    plt.title('Original Histogram')

    # Plot the cumulative distribution function (CDF)
    plt.subplot(2, 3, 3)
    plt.plot(cdf, color='r')
    plt.title('CDF of Original Image')

    # Plot the equalized image and its histogram
    plt.subplot(2, 3, 4)
    plt.imshow(equalized_img, cmap='gray')
    plt.title('Equalized Image')
    plt.axis('off')

    plt.subplot(2, 3, 5)
    plt.plot(equalized_hist, color='b')
    plt.title('Equalized Histogram')

    # Plot the normalized cumulative distribution function (CDF)
    plt.subplot(2, 3, 6)
    plt.plot(equalized_cdf_normalized, color='r')
    plt.title('CDF of Equalized Image')


    plt.tight_layout()
    plt.show()

# Provide the path to your image here
image_path = 'flower.webp'

# Perform histogram equalization and display the results
histogram_equalization(image_path)


