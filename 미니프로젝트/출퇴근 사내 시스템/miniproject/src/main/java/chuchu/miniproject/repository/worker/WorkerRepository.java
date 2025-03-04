package chuchu.miniproject.repository.worker;

import chuchu.miniproject.domain.worker.Worker;
import org.springframework.data.jpa.repository.JpaRepository;

public interface WorkerRepository extends JpaRepository<Worker, Long> {

}
