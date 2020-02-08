import tensorflow as tf
import sea

model = tf.keras.Sequntial([
    tf.keras.layers.Flatten(input=(10, 10)),
    tf.layers.Dense(10 * 10),
    tf.layers.Dense(20),
    tf.layers.Dense(1)
])
