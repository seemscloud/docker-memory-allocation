FROM debian:bullseye-slim

ARG APP_DIR="/app"
ARG APP_USER="malloc"
ARG APP_GROUP="malloc"
ARG APP_UID="1000"
ARG APP_GID="1000"
ENV PATH="${APP_DIR}/bin:${PATH}"

RUN groupadd -g "${APP_GID}" "${APP_GROUP}" && \
    useradd -u "${APP_UID}" -g "${APP_GID}" -s /bin/bash -m -d "${APP_DIR}" "${APP_USER}"

RUN mkdir -p "${APP_DIR}/bin"

RUN apt-get update && \
    apt-get install g++ -y

COPY ./files/allocation.cpp "${APP_DIR}"

RUN g++ "${APP_DIR}/allocation.cpp" -o "${APP_DIR}/bin/allocation"

RUN chmod +x "${APP_DIR}/bin/allocation" && \
    chown "${APP_USER}":"${APP_USER}" -R ${APP_DIR}

WORKDIR "${APP_DIR}"

USER "${APP_USER}"

CMD ["allocation", "100", "1000", "1000"]